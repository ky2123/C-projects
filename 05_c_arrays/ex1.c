#include <stdio.h>

static const int NUMS_1[] = {7, 200, 30, 40, 50, 5, 3};
static const size_t NUMS_1_SIZE = sizeof NUMS_1 / sizeof NUMS_1[0];

static const int NUMS_2[] = {-13, -6, -1, -5};
static const size_t NUMS_2_SIZE = sizeof NUMS_2 / sizeof NUMS_2[0];

// TODO implement find_largest
int find_largest(const int arr[], size_t size) {
	int largest = arr[0];
	for (size_t i = 1; i < size; i++) {
		if (arr[i] > largest) {
			largest = arr[i];
		}
	}
	return largest;
} 


int main(void) {
  printf("largest (1) is %d\n", find_largest(NUMS_1, NUMS_1_SIZE));
  printf("largest (2) is %d\n", find_largest(NUMS_2, NUMS_2_SIZE));
}
