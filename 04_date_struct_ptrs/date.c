#include "date.h"

#include <stdio.h>

// TODO: definitions for all functions that are declared in date.h
int date_cmp(const struct Date* d1, const struct Date* d2){
	if (d1 -> year > d2 -> year){
		return 1;
	}else if (d1 -> year < d2 -> year){
		return -1;
	}else if(d1 -> month > d2 -> month){
		return 1;
	}else if(d1 -> month < d2 -> month){
		return -1;
	}else if(d1 -> day > d2 -> day){
		return 1;
	}else if(d1 -> day < d2 -> day){
		return -1;
	}else{
		return 0;
	}
}
bool is_valid_date(const struct Date* d){
        if (d -> month< 1 || d -> month > 12){
        return 0;
        }
        if (d -> day < 1 || d -> day > 31){
        return 0;
        }
        if (d -> day > 30 && (d -> month == 4 || d -> month == 6 || d -> month == 9 || d -> month == 11)){
        return 0;
        }
        if (d -> month == 2 && d -> year % 4 != 0 && d -> day > 28){
        return 0;
        }
        if (d -> month == 2 && d -> year % 4 == 0 && d -> day > 30){
        return 0;
        }else{
        return 1;
        }
}
void print_date(const struct Date* d){
        printf("%d/%d/%d\n", d -> year, d -> month, d -> day);
}
void increment_date(struct Date* d){
	d -> day += 1;
	if (!is_valid_date(d)) {
		d -> day = 1;		
		d -> month += 1;
		if (d -> month > 12) {
			d -> month = 1;
			d -> year += 1;	
		}	
	}
}
void decrement_date(struct Date* d){
	d -> day -= 1;
	if (is_valid_date(d) == false) {
		d -> day = 31;
		d -> month -= 1;
		if (d -> month > 0) {
			d -> month = 1;
			d -> year -= 1;
	
			}
		}
	while (is_valid_date(d) == false) {
		d -> day -= 1;
	}	
}
struct Date next_date(const struct Date* d){
	struct Date a = *d;
	increment_date(&a); 
	return a;
}
struct Date prev_date(const struct Date* d){
	struct Date b = *d; 
	decrement_date(&b);
	return b;
}
void swap_dates(struct Date* d1, struct Date* d2){
	struct Date d3 = *d1;
	*d1 = *d2;
	*d2 = d3;	
}

