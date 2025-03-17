#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

static const int NUMS_1[] = {7, 200, 30, 40, 50, 5, 3};

// TODO implement contains
bool contains(const int* a,const int* b, int c) {
  bool flag = false;
  int index1 = a - NUMS_1;
  int index2 = b - NUMS_1; 
  for(size_t i = index1; i < (size_t)index2; i++) {
    if (NUMS_1[i] == c){
      flag = true;
    }  
  }
  return flag;
} 
int main(void) {
    assert(contains(NUMS_1, NUMS_1+3, 30));
    assert(!contains(NUMS_1, NUMS_1+2, 30));

    assert(contains(NUMS_1+1, NUMS_1+4, 30));
    assert(contains(NUMS_1+1, NUMS_1+4, 40));
    assert(contains(NUMS_1+1, NUMS_1+4, 200));
    assert(!contains(NUMS_1+1, NUMS_1+4, 7));

    assert(!contains(NUMS_1, NUMS_1, 7));
}
