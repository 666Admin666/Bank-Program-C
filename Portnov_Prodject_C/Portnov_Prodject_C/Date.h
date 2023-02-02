#include "Lib.h"

struct Date {
	int year = 0;
	int month = 0;
	int day = 0;
	void fillDate() {
		cout << "Write date, if you set wrong day or month they value will be 1 " << endl;
		cout << "Enter year: ";
		cin >> year;
		cout << "Enter month: ";
		cin >> month;
		month = (month > 12 || month < 1) ?  1 : month;
		cout << "Enter day: ";
		cin >> day;
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			(day > 31 || day < 1) ? day=1  : day=day ;
		else if (month == 4 || month == 6 || month == 9 || month == 11)
			(day > 30 || day < 1) ? day = 1 : day = day;
		else if (isLeapYear())
			(day > 29 || day < 1) ? day = 1 : day = day;
		else
			(day > 28 || day < 1) ? day = 1 : day = day;
	}
	void PrintDate(){
		cout<< day << "." << month << "." << year << endl;
	}
	bool isLeapYear() {
		if (year % 4 == 0 && !(year % 100 == 0 && year % 400 != 0))
			return true;
		else
			return false;
	}
};