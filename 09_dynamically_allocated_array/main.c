#include "intarray.h"
#include <stdio.h>
#include <assert.h>

static double average(const struct IntArray* grades) {
  double total = 0;
  for (size_t i = 0; i < grades->size; ++i) {
    total += grades->data[i];
  }
  return total / grades->size;
}

static int times2(int n) {
  return n * 2;
}


static void example_use_case() {
  printf("Homework average calculator\n");

  printf("Enter number of grades: ");
  size_t num_grades = 0;
  scanf("%zu", &num_grades);

  struct IntArray* grades = create_array(num_grades);
  printf("Enter grades:\n");
  for (size_t i = 0; i < grades->size; ++i) {
    scanf("%d", &grades->data[i]);
  }

  printf("Your average is %lf\n", average(grades));
  free_array(grades);
}

static void test_array(void) {
  struct IntArray* a1 = create_array(4);
  assert(a1->size == 4);

  a1->data[0] = 12;
  a1->data[1] = 20;
  a1->data[2] = -2;
  a1->data[3] = 5;

  printf("max element: %d\n", max_element(a1));
  printf("min element: %d\n", min_element(a1));

  printf("contains 5?: %d\n", contains(a1, 5));
  printf("contains 20?: %d\n", contains(a1, 20));
  printf("contains 13?: %d\n", contains(a1, 13));

  struct IntArray* doubled_array = map_array(a1, times2);

  free_array(a1);
  a1 = NULL; // it's a good idea to set pointers to NULL after freeing them
  // it's a clear indication that the memory is no longer owned by you and
  // the pointer is no longer valid
  
  assert(doubled_array->size == 4);
  assert(doubled_array->data[0] == 24);
  assert(doubled_array->data[1] == 40);
  assert(doubled_array->data[2] == -4);
  assert(doubled_array->data[3] == 10);

  free_array(doubled_array);

  struct IntArray* a2 = create_array(5);
  struct IntArray* a3 = create_array(5);
  for (size_t i = 0; i < a2->size; ++i) {
    a2->data[i] = a3->data[i] = i * i;
  }
  printf("they should now be equal(1): %d\n", equals(a2, a3));
  a2->data[2] = -1;
  printf("they should now be unequal(0): %d\n", equals(a2, a3));

  struct IntArray* big_array = create_array(1024);
  printf("arrays of different sizes should always be unequal (0, 0): %d, %d\n",
         equals(a2, big_array), equals(big_array, a2));
  free_array(big_array);
  big_array = NULL;
  free_array(a3);
  a3 = NULL;
  free_array(a2);
  a2 = NULL;

  // comment this out if you don't want to use the interactive example
  example_use_case();
}

int main(void) {
  test_array();
}
