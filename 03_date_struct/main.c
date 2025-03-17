main.c:25:3: error: expected declaration or statement at end of input
   25 |   printf("should be 0, valid?: %d\n", is_valid_date(invalid_day));
      |   ^~~~~~#include "date.h"

#include <stdio.h>

int main(void) {
  struct Date christmas95 = {.year=1995, .day=25, .month=12};

  // 1 true, 0 false
  printf("should be 1, valid?: %d\n", is_valid_date(christmas95));
  
  struct Date valentines96 = {.year=1996, .month=2, .day=14};

  struct Date earlier = earlier_date(christmas95, valentines96);
  printf("earlier: ");
  print_date(earlier);

  struct Date later = later_date(christmas95, valentines96);
  printf("later: ");
  print_date(later);

  struct Date invalid_month = {.year=2000, .month=14, .day=1};
  printf("should be 0, valid?: %d\n", is_valid_date(invalid_month));

  struct Date invalid_day = {.year=2000, .month=3, .day=50};
  printf("should be 0, valid?: %d\n", is_valid_date(invalid_day));
}
