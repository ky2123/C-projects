#include <stdio.h>

static const int NUMS_1[] = {7, 200, 30, 40, 50, 5, 3};
static const size_t NUMS_1_SIZE = sizeof NUMS_1 / sizeof NUMS_1[0];

static const int NUMS_2[] = {-13, -6, -1, -5};
static const size_t NUMS_2_SIZE = sizeof NUMS_2 / sizeof NUMS_2[0];

// TODO define your own NUMS_3
static const int NUMS_3[] = {5, 10, 15, 20};
static const size_t NUMS_3_SIZE = sizeof NUMS_3 / sizeof NUMS_3[0];
// TODO implement sum_array
int sum_array(const int arr[], size_t size) {
	int ans = 0;
	for (size_t i = 0; i < size; i++) {
		ans += arr[i];
	}
	return ans;
}

int main(void) {
  printf("sum (1) is %d\n", sum_array(NUMS_1, NUMS_1_SIZE));
  printf("sum (2) is %d\n", sum_array(NUMS_2, NUMS_2_SIZE));
  printf("sum (3) is %d\n", sum_array(NUMS_3, NUMS_3_SIZE));
}
