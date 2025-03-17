#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static const int NUMS_1[] = {7, 200, 30, 40, 50, 5, 3};
static const size_t NUMS_1_SIZE = sizeof NUMS_1 / sizeof NUMS_1[0];

static const int NUMS_2[] = {-13, -6, -1, -5};
static const size_t NUMS_2_SIZE = sizeof NUMS_2 / sizeof NUMS_2[0];


// TODO implement concat_arrays using malloc to create the array that
// you return.
// The result should be the first array's elements followed by the second
// like the + operator.
int* concat_arrays(const int arr_1[], size_t size_1, const int arr_2[], size_t size_2){
	size_t total_size = size_1 + size_2;
	int* con_arr = malloc(total_size * sizeof(int));
	for(size_t i = 0; i < size_1; i++) {
		con_arr[i] = arr_1[i];
	}
	for(size_t i = 0; i < size_2; i++) {
		con_arr[i+size_1] = arr_2[i];
	}
	return con_arr;
}
int main(void) {
  int* result = concat_arrays(NUMS_1, NUMS_1_SIZE, NUMS_2, NUMS_2_SIZE);
  
  for (size_t i = 0; i < NUMS_1_SIZE + NUMS_2_SIZE; ++i) {
    printf("result[%zu] = %d\n", i, result[i]);
  }

  free(result);
}
