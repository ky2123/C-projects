#include <stdio.h>

static const int NUMS_1[] = {7, 200, 30, 40, 50, 5, 3};

static void print_range(const int* first, const int* last) {
  size_t size = sizeof NUMS_1 / sizeof NUMS_1[0];
  printf("%d\n", *first);
  for (size_t i = 2; i < size; i++) {
    if (NUMS_1[i] != *last) {
      printf("%d\n", NUMS_1[i]);
    } else {
      break;
    }
  }
  // TODO implement print_range with inclusive first and exclusive last
  // print each element on its own line
}
int main(void) {
  // should print 200, 30, 40
  print_range(NUMS_1+1, NUMS_1+4);
}
