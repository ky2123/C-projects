#include <stdio.h>

#include "date.h"

int main(void) {
  struct Date christmas95 = {.year = 1995, .day = 25, .month = 12};

  // 1 true, 0 false
  printf("should be 1, valid?: %d\n", is_valid_date(&christmas95));

  struct Date valentines96 = {.year = 1996, .month = 2, .day = 14};

  const struct Date *earlier =
      date_cmp(&christmas95, &valentines96) < 0 ? &christmas95 : &valentines96;
  printf("earlier: ");
  print_date(earlier);

  const struct Date *later =
      date_cmp(&christmas95, &valentines96) > 0 ? &christmas95 : &valentines96;
  printf("later: ");
  print_date(later);

  struct Date invalid_month = {.year = 2000, .month = 14, .day = 1};
  printf("should be 0, valid?: %d\n", is_valid_date(&invalid_month));

  struct Date invalid_day = {.year = 2000, .month = 3, .day = 50};
  printf("should be 0, valid?: %d\n", is_valid_date(&invalid_day));

  struct Date new_years = {.year = 2050, .month = 12, .day = 31};
  printf("should be new years eve 2050: ");
  print_date(&new_years);

  increment_date(&new_years);
  printf("should be new years day 2051: ");
  print_date(&new_years);

  decrement_date(&new_years);
  printf("should be back to new years eve 2050: ");
  print_date(&new_years);

  struct Date april_end = {.year = 2040, .month = 4, .day = 30};
  printf("should be end of April: ");
  print_date(&april_end);

  increment_date(&april_end);
  printf("should be beginning of May: ");
  print_date(&april_end);

  decrement_date(&april_end);
  printf("should be back to end April: ");
  print_date(&april_end);

  increment_date(&april_end);
  increment_date(&april_end);
  printf("should be May 2: ");
  print_date(&april_end);

  struct Date halloween35 = {.year = 2035, .month = 10, .day = 31};
  struct Date nov35 = next_date(&halloween35);
  printf("should still be halloween: ");
  print_date(&halloween35);
  printf("should be nov 1: ");
  print_date(&nov35);

  struct Date mid_sep = {.year = 2035, .month = 9, .day = 15};
  struct Date before_mid_sep = prev_date(&mid_sep);
  printf("should still be sept 15: ");
  print_date(&mid_sep);
  printf("should be sept 14: ");
  print_date(&before_mid_sep);

  {
    struct Date d1 = {.year = 2037, .month = 4, .day = 10};
    struct Date d2 = {.year = 2039, .month = 8, .day = 20};
    swap_dates(&d1, &d2);
    printf("should be aug 20 2039: ");
    print_date(&d1);
    printf("should be april 10  2037: ");
    print_date(&d2);
  }
}
