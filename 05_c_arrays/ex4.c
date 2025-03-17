#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static const int NUMS_1[] = {7, 200, 30, 40, 50, 5, 3};
static const size_t NUMS_1_SIZE = sizeof NUMS_1 / sizeof NUMS_1[0];

static const int NUMS_2[] = {-13, -6, -1, -5};
static const size_t NUMS_2_SIZE = sizeof NUMS_2 / sizeof NUMS_2[0];


// TODO implement duplicate_array using malloc to create the array that
// you return
int* duplicate_array(const int arr[], size_t size) {
	int* dup_arr = malloc(size *sizeof(int));
	for(size_t i =0; i < size; i++) {
		dup_arr[i] = arr[i];
	}
	return dup_arr;
}

static void check_arrays_equal(const int a1[], const int a2[], size_t length) {
  for (size_t i = 0; i < length; ++i) {
    if (a1[i] != a2[i]) {
      fprintf(stderr, "error at index %zu\n", i);
    }
  }
}


int main(void) {
  // should only print if there's an error
  int* n1_copy = duplicate_array(NUMS_1, NUMS_1_SIZE);
  assert(n1_copy != NUMS_1); // must not be the same pointer
  printf("checking NUMS_1 copy\n");
  check_arrays_equal(n1_copy, NUMS_1, NUMS_1_SIZE);

  int* n2_copy = duplicate_array(NUMS_2, NUMS_2_SIZE);
  assert(n2_copy != NUMS_2);
  printf("checking NUMS_2 copy\n");
  check_arrays_equal(n2_copy, NUMS_2, NUMS_2_SIZE);

  free(n2_copy);
  free(n1_copy);
}
