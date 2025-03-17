#ifndef CSIDE_DATE_H_
#define CSIDE_DATE_H_

#include <stdbool.h>


struct Date
{
	int year;
	int day;
	int month;
}; 
// done for you: function declarations. Your definitions should have
// the same signatures

// if d1 is earlier than d2, return a negative value
// if d1 is later than d2, return a positive value
// if they are the same, return 0
int date_cmp(struct Date d1, struct Date d2);
// return whichever date is earliest
struct Date earlier_date(struct Date d1, struct Date d2);
// return whichever date is later
struct Date later_date(struct Date d1, struct Date d2);

// return true if the Date is a legit date with the following constraints
// any year is considered valid
// month must be at least 1 and at most 12
// day is at least 1
// day is at most 30 if month is 4, 6, 9, or 11
// day is at most 28 if month is 2 and it is NOT a leap year (year % 4 != 0)
// day is at most 29 if month is 2 and it IS a leap year (year % 4 == 0)
// otherwise, day is at most 31
bool is_valid_date(struct Date d);

// print the date it day/month/year format
void print_date(struct Date d);

#endif
