#include <assert.h>
#include <stdio.h>

// TODO implement reverse
void reverse(int* a, int* b) {
  // int index1 = a - nums_1;
  // int index2 = b - nums_1;
  int temp = 0;
  b--;
  while (a < b) {
    temp = *a;
    *a = *b;
    *b = temp; 
    a++;
    b--; 
  }
}
int main(void) {
    int nums_1[] = {7, 200, 30, 40, 50, 5, 3, 1, -1, -3, -5};
    reverse(nums_1+1, nums_1+5);
    assert(nums_1[0] == 7); // unchanged
    assert(nums_1[1] == 50);
    assert(nums_1[2] == 40);
    assert(nums_1[3] == 30);
    assert(nums_1[4] == 200);
    assert(nums_1[5] == 5); //unchanged

    int nums_2[] = {7, 200, 30, 40, 50, 5, 3, 1, -1, -3, -5};
    reverse(nums_2+2, nums_2+7);
    assert(nums_2[0] == 7); // unchanged
    assert(nums_2[1] == 200); // unchanged
    assert(nums_2[2] == 3);
    assert(nums_2[3] == 5);
    assert(nums_2[4] == 50);
    assert(nums_2[5] == 40);
    assert(nums_2[6] == 30);
    assert(nums_2[7] == 1); // unchanged
    assert(nums_2[8] == -1); // unchanged

    int nums_3[] = {5, 7, 9};
    reverse(nums_3+1, nums_3+1); // shouldn't do anything
    assert(nums_3[0] == 5);
    assert(nums_3[1] == 7);
    assert(nums_3[2] == 9);
}
