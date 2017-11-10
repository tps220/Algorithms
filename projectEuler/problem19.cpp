//Thomas Salemy
//Project Euler Solutions
//Problem 19: Counting Sundays
//Question: How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

#include <iostream>
#include <time.h>
using namespace std;


void isSunday(int *day, int* sundays) {
	if (*day == 6) {
		*sundays += 1;
	}
}

int main() {

    clock_t time = clock();
    int day = 0;
    
    //Account for year 1900 having two sundays that fit the requirements
    int sundays = -2;
    int year = 1900;
    int month = 0;
    int *ptrSunday = &sundays;
    int *ptrDay = &day;

    while (year <= 2000) {
	    switch(month) {
		//January
		case 0:
			isSunday(ptrDay, ptrSunday);
			day += 31;
			day %= 7;
		//February
		case 1:
			isSunday(ptrDay, ptrSunday);
			day += 28;
			if (year % 100 == 0) {
				if (year % 400 == 0) {
					day++;
				}
			}
			else if (year % 4 == 0) {
				day++;
			}	
			day %= 7;	
		//March
		case 2:
			isSunday(ptrDay, ptrSunday);
			day += 31;
			day %= 7;
		//April
		case 3:
			isSunday(ptrDay, ptrSunday);
			day += 30;
			day %= 7;
		//May
		case 4:
			isSunday(ptrDay, ptrSunday);
			day+= 31;
			day %= 7;
		//June
		case 5:
			isSunday(ptrDay, ptrSunday);
			day += 30;
			day %= 7;
		//July
		case 6:
			isSunday(ptrDay, ptrSunday);
			day+= 31;
			day %= 7;
		//August
		case 7:
			isSunday(ptrDay, ptrSunday);
			day += 31;
			day %= 7;	
		//September
		case 8:
			isSunday(ptrDay, ptrSunday);
			day+= 30;
			day %= 7;
		//October
		case 9:
			isSunday(ptrDay, ptrSunday);
			day += 31;
			day %= 7;
		//Novemeber
		case 10:
			isSunday(ptrDay, ptrSunday);
			day += 30;
			day %= 7;
		//December
		case 11:
			isSunday(ptrDay, ptrSunday);
			day += 31;
			day %= 7;
			break;
	    }
	year++;
    }

    cout << "Answer: " << sundays << endl;
    cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;

    return 1;

};
