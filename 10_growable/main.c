#include "growable_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Date {
  int year;
  int month;
  int day;
};

static int date_cmp(const void* lhs_vp, const void* rhs_vp) {
  const struct Date* lhs = lhs_vp;
  const struct Date* rhs = rhs_vp;
  return lhs->year < rhs->year ? -1
    : lhs->year > rhs->year ? 1
    : lhs->month < rhs->month ? -1
    : lhs->month > rhs->month ? 1
    : lhs->day < rhs->day ? -1
    : lhs->day > rhs->day ? 1
    : 0;
}

static struct Date* create_date(int year, int month, int day) {
  struct Date* d = malloc(sizeof *d);
  *d = (struct Date){.year=year, .month=month, .day=day};
  return d;
}

static void* duplicate_date(const void* date_vp) {
  const struct Date* date = date_vp;
  return create_date(date->year, date->month, date->day);
}

static void date_example(void) {
  {
    struct GrowableArray* a = create_array(date_cmp, free, duplicate_date);
    assert(a->size == 0);
    free_array(a);
  }

  {
    struct GrowableArray* a = create_array(date_cmp, free, duplicate_date);
    append(a, create_date(2019, 6, 2));
    append(a, create_date(2016, 6, 2));
    append(a, create_date(2020, 3, 2));
    append(a, create_date(2020, 4, 2));
    append(a, create_date(2019, 4, 2));

    struct Date* max_date = max_element(a);
    assert(max_date->year == 2020);
    assert(max_date->month == 4);
    assert(max_date->day == 2);

    struct Date* min_date = min_element(a);
    assert(min_date->year == 2016);

    struct Date* last_date = pop(a);
    assert(a->size == 4);
    free(last_date);
    free_array(a);
  }

  {
    struct GrowableArray* a = create_array(date_cmp, free, duplicate_date);
    append(a, create_date(2019, 6, 2));
    append(a, create_date(2016, 6, 2));

    struct GrowableArray* copy = duplicate(a);
    assert(copy->size == 2);

    struct Date* max_date = max_element(copy);
    assert(max_date->year == 2019);

    free_array(copy);
    free_array(a);
  }

  {
    struct GrowableArray* a = create_array(date_cmp, free, duplicate_date);
    append(a, create_date(2019, 6, 2));
    append(a, create_date(2016, 6, 2));

    struct Date* needle = create_date(2019, 6, 2);
    assert(contains(a, needle));

    needle->day = 20;
    assert(!contains(a, needle));

    free(needle);
    free_array(a);
  }

  {
    struct GrowableArray* a1 = create_array(date_cmp, free, duplicate_date);
    append(a1, create_date(2019, 6, 2));
    append(a1, create_date(2016, 6, 2));

    struct GrowableArray* a2 = create_array(date_cmp, free, duplicate_date);
    append(a2, create_date(2019, 6, 2));
    append(a2, create_date(2016, 6, 2));

    assert(equals(a1, a2));

    append(a2, create_date(2017, 6, 2));
    assert(!equals(a1, a2));

    free(pop(a2));
    assert(equals(a1, a2));

    free_array(a2);
    free_array(a1);
  }

  {
    struct GrowableArray* a1 = create_array(date_cmp, free, duplicate_date);
    append(a1, create_date(2019, 6, 2));

    struct GrowableArray* a2 = create_array(date_cmp, free, duplicate_date);
    append(a2, create_date(2016, 6, 2));

    assert(!equals(a1, a2));

    free_array(a2);
    free_array(a1);
  }

  {
    struct GrowableArray* a1 = create_array(date_cmp, free, duplicate_date);
    append(a1, create_date(2019, 6, 2));
    append(a1, create_date(2016, 6, 2));

    struct GrowableArray* a2 = create_array(date_cmp, free, duplicate_date);
    append(a2, create_date(2020, 6, 2));
    append(a2, create_date(2021, 11, 2));
    append(a2, create_date(2023, 10, 2));

    extend(a1, a2);

    struct GrowableArray* expected = create_array(date_cmp, free, duplicate_date);
    append(expected, create_date(2019, 6, 2));
    append(expected, create_date(2016, 6, 2));
    append(expected, create_date(2020, 6, 2));
    append(expected, create_date(2021, 11, 2));
    append(expected, create_date(2023, 10, 2));

    assert(equals(a1, expected));

    free_array(expected);
    free_array(a2);
    free_array(a1);
  }

  {
    struct GrowableArray* a1 = create_array(date_cmp, free, duplicate_date);
    append(a1, create_date(2019, 6, 2));
    append(a1, create_date(2016, 6, 2));

    struct GrowableArray* a2 = create_array(date_cmp, free, duplicate_date);
    append(a2, create_date(2020, 6, 2));
    append(a2, create_date(2021, 11, 2));
    append(a2, create_date(2023, 10, 2));

    struct GrowableArray* result = concat(a1, a2);

    struct GrowableArray* expected = create_array(date_cmp, free, duplicate_date);
    append(expected, create_date(2019, 6, 2));
    append(expected, create_date(2016, 6, 2));
    append(expected, create_date(2020, 6, 2));
    append(expected, create_date(2021, 11, 2));
    append(expected, create_date(2023, 10, 2));

    assert(equals(result, expected));

    free_array(expected);
    free_array(result);
    free_array(a2);
    free_array(a1);
  }
}

static int dummy_array_compare(const void* lhs, const void* rhs) {
  // silencing the unused parameter warnings, normally you'd want to actually
  // use your arguments
  (void)lhs;
  (void)rhs;
  return 0;
}

static void free_array_wrapper(void* array) {
  free_array(array);
}

static void* duplicate_array_wrapper(const void* array) {
  return duplicate(array);
}

static void nested_example(void) {
  struct GrowableArray* date_array1 = create_array(date_cmp, free, duplicate_date);
  struct GrowableArray* date_array2 = create_array(date_cmp, free, duplicate_date);

  struct GrowableArray* array_of_arrays =
    create_array(dummy_array_compare, free_array_wrapper, duplicate_array_wrapper);
  append(array_of_arrays, date_array1);
  append(array_of_arrays, date_array2);

  free_array(array_of_arrays);
}


int main(void) {
  date_example();
  nested_example();
}
