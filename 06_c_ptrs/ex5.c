#include <assert.h>
#include <stdio.h>


static int times2(int i) { return i*2; }

struct Date {
  int year;
  int month;
  int day;
};
typedef const int integer;
typedef const int* cint_ptr;
typedef unsigned int* uint_ptr;
typedef int (*int_func)(int);
typedef int int_array[];
typedef struct Date DateArray[];

// TODO write typedefs that makes everything below compile.

int main(void) {
  const int n = 0;
  unsigned int un;

  integer i = 0;
  cint_ptr cp = &n;
  uint_ptr up = &un;
  int_func f = times2;
  int_array a = {3, 5, 10};
  DateArray da = {{.year=2020, .month=1, .day=1}, {.year=3000, .month=6, .day=20}};

  // These are here to suppress the unused variable warnings
  (void)i;
  (void)cp;
  (void)up;
  (void)f;
  (void)a;
  (void)da;
}
