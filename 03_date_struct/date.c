#include "date.h"

#include <stdio.h>

struct Date later_date(struct Date d1, struct Date d2){
	if (d1.year > d2.year){
	return d1;
	}else if (d2.year > d1.year){
	return d2;
	}else if (d1.month > d2.month){
	return d1;
	}else if (d2.month > d1.month){
	return d2;
	}else if (d1.day > d2.day){ return d1;
	}else if (d2.day > d1.day){
	return d2;
	} else {
	return d1;	
	}	
}
// TODO write using date_cmp
struct Date earlier_date(struct Date d1, struct Date d2){
	if (d1.year < d2.year){
	return d1;
	}else if (d2.year < d1.year){
	return d2;
	}else if (d1.month < d2.month){
	return d1;
	}else if (d2.month < d1.month){
	return d2;
	}else if (d1.day < d2.day){
	return d1;
	}else if (d2.day < d1.day){
	return d2;
	} else {
	 return d1;	
	}	
}
int date_cmp(struct Date d1, struct Date d2){
	if (d1.year > d2.year){
	return 1;
	}else if (d1.year < d2.year){
	return -1;
	}else if(d1.month > d2.month){
	return 1;
	}else if(d1.month < d2.month){
	return -1;
	}else if(d1.day > d2.day){
	return 1;
	}else if(d1.day < d2.day){
	return -1;
	}else{
	return 0;
	}
}
bool is_valid_date(struct Date d){
	if (d.month < 1 || d.month > 12){
	return 0; 
	}
	if (d.day < 1 || d.day > 31){
	return 0;
	}
	if (d.day > 30 && (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11)){
	return 0;
	}
	if (d.month == 2 && d.year % 4 != 0 && d.day > 28){
	return 0;
	}
	if (d.month == 2 && d.year % 4 == 0 && d.day > 30){ 
	return 0;
	}else{
	return 1;
	}	
}
void print_date(struct Date d){
	printf("%d/%d/%d\n", d.day, d.month, d.year);
} 
