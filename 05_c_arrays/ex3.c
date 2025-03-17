#include <stdio.h>


// TODO implement increment_all to increase every element of an array by 1.
void increment_all(int arr[], size_t size) {
	for (size_t i = 0; i < size; i++) {
		arr[i]++;
	}
}

int main(void) {
  int nums[] = {7, 200, 30, 40, 50, 5, 3};
  size_t nums_size = sizeof nums / sizeof nums[0];

  increment_all(nums, nums_size);

  for (size_t i = 0; i < nums_size; ++i) {
    printf("nums[%zu] = %d\n", i, nums[i]);
  }
}
