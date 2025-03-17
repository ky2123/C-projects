#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static const int NUMS_1[] = {7, 200, 30, 40, 50, 5, 3};
static const size_t NUMS_1_SIZE = sizeof NUMS_1 / sizeof NUMS_1[0];

static const int NUMS_2[] = {-13, -6, -1, -5};
static const size_t NUMS_2_SIZE = sizeof NUMS_2 / sizeof NUMS_2[0];


struct Pair {
  int first;
  int second;
};

// TODO implement zip_arrays to return an array of Pairs of the elements.
// terminate on the shorter array.
struct Pair* zip_arrays(const int arr_1[], size_t size_1, const int arr_2[], size_t size_2) {
  size_t min_size = (size_1 < size_2) ? size_1 : size_2; 
  struct Pair* zip_arr = malloc(min_size * sizeof(struct Pair));
  for(size_t i = 0; i < min_size; i++) {
    zip_arr[i].first = arr_1[i];
    zip_arr[i].second = arr_2[i];
  }
  return zip_arr;
}

int main(void) {
  size_t length = NUMS_1_SIZE < NUMS_2_SIZE ? NUMS_1_SIZE : NUMS_2_SIZE;

  struct Pair* result_1 = zip_arrays(NUMS_1, NUMS_1_SIZE, NUMS_2, NUMS_2_SIZE);
  for (size_t i = 0; i < length; ++i) {
    printf("result_1[%zu] = (%d, %d)\n", i, result_1[i].first, result_1[i].second);
  }

  printf("----------------\n");

  struct Pair* result_2 = zip_arrays(NUMS_2, NUMS_2_SIZE, NUMS_1, NUMS_1_SIZE);
  for (size_t i = 0; i < length; ++i) {
    printf("result_2[%zu] = (%d, %d)\n", i, result_2[i].first, result_2[i].second);
  }

  free(result_2);
  free(result_1);
}
