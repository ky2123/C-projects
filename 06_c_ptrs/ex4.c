#include <assert.h>
#include <stdio.h>

// TODO implement for_each which applies a function to each element
void for_each(int *a, int *b, void (*func)(int*)) {
 for(int* i = a; i < b; i++) {
   func(i);
  }
} 

static void mul2(int* p) {
  *p *= 2;
}

static void increment(int* p) {
  ++*p;
}

int main(void) {
  int NUMS_1[] = {7, 200, 30, 40, 50, 5, 3};
  for_each(NUMS_1+1, NUMS_1+3, mul2);
  assert(NUMS_1[0] == 7);  // unchanged
  assert(NUMS_1[1] == 400);
  assert(NUMS_1[2] == 60);
  assert(NUMS_1[3] == 40);  // unchanged

  for_each(NUMS_1+4, NUMS_1+6, increment);
  assert(NUMS_1[3] == 40);  // unchanged
  assert(NUMS_1[4] == 51);
  assert(NUMS_1[5] == 6);
  assert(NUMS_1[6] == 3);  // unchanged
}

