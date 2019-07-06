/*
* This project is to allow user to query any given date and print our calender for a given month or year.
* Author: Yun-feng Zhao
* Version: June 28, 2019

*/

#include <iostream>
#include <string>
using namespace std;

void testMenu();
// post-condition: the test menu is displayed for choose
bool isLeapYear(int year);
//precondition: year since 1600s
//postcondition: return True if the given year is a leap year; otherwise return False
int getCenturyValue(int year);
//pre: the years since the beginning of the century
//post: take the first two digits of a year and divide by 4, use 3 - the remainder and times 2 at the end.

int getYearValue(int year);
//pre: the years since the beginning of the century
//return the result of the last two digits of the year + itself divided by 4

int getMonthValue(int month, int year);
//the month and year since the begining of the century.
//post:return a value based on the corresponding value in the book. This requires invoking the isLeapYear function
int dayOfWeek(int month, int day, int year);

string dayOfWeek(int day);
// pre-condition: day has integer value 0, 1, 2, 3, 4, 5, or 6
// post-condition: the name of the day of week is returned as a std::. If day
//has value 0, then SUNDAY is returned; 1, then MONDAY is returned;and so on.

int main()
{
	using namespace std;
	int choice;
	int day, month, year;
	do
	{
		testMenu();
		cout << "Please choose from menu: ";
		cin >> choice;
		switch (choice)
		{
		case 1: // check if a given year is leap year
			cout << "Please enter a year: ";
			cin >> year;
			if (isLeapYear(year))
				cout << "Year " << year << " is a leap year" << endl;
			else
				cout << "Year " << year << " is NOT a leap year" << endl;
			break;
		case 2: // calculate the century value of a given year
			cout << "Please enter a year: ";
			cin >> year;
			cout << "The century value is: " << getCenturyValue(year) << endl;
			break;
		case 3: // calculate the year value of a given year
			cout << "Please enter a year: ";
			cin >> year;
			cout << "The year value is: " << getYearValue(year) << endl;
			break;
		case 4: // calculate the month value of a given month in a given year
			cout << "Please enter a year and month: ";
			cin >> year >> month;
			cout << "The month value is: " << getMonthValue(month, year) <<
				endl;
			break;
		case 5: // calculate the day of week of a given date
			cout << "Please enter a month, a day, and a year : ";
			cin >> month >> day >> year;
			cout << "The day of the week is: " << dayOfWeek(month, day, year)
				<< endl;
			break;
		case 6: // print out the name of a given day of week
			cout << "Please enter a day of week (0 for Sunday, 1 for Monday,etc): ";
				cin >> day;
			cout << "The name of the day of the week is: " << dayOfWeek(day)
				<< endl;
			break;
		case 7:
			cout << "Did you tested all functions yet ? if not, please rerun the program\n";
				break;
		default:
			cout << "wrong option. Please choose from menu\n";
			break;
		}
		system("pause");
	} while (choice != 7);
}

void testMenu() {
	{
		cout << "*************************************\n";
		cout << "* Test Menu                         *\n";
		cout << "* 1. isLeapYear                     *\n";
		cout << "* 2. getCenturyValue                *\n";
		cout << "* 3. getYearValue                   *\n";
		cout << "* 4. getMonthValue                  *\n";
		cout << "* 5. dayOfWeek(month, day, year)    *\n";
		cout << "* 6. dayOfWeek(day)                 *\n";
		cout << "* 7. Quit                           *\n";
		cout << "*************************************\n";
	}

}

bool isLeapYear(int year) {
	// a year is leap if year is divisible by 400 or ( divisible by 4 and not divisible by 100)
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int getCenturyValue(int year) {
	//get first two digits of the year
	int century = year / 100;
	//divide it by 4 and save the remainder
	int result = century % 4;
	//subtract remainder from 3
	result = 3 - result;
	//return this value multiplied by 2
	return result * 2;
}

int getYearValue(int year) {
	//get last two digits of the year
	int last_two_digit = year % 100;
	//divide value from previous step by 4 and discard the remainder
	int result = last_two_digit / 4;
	// add two results together and return a value
	return result + last_two_digit;
}

int getMonthValue(int month, int year)
{
	int monthReturn;
	switch (month)
	{
	case 1:
		if (isLeapYear(year))
		{
			monthReturn = 6;
		}
		else
		{
			monthReturn = 0;
		}
		break;
	case 2:
		if (isLeapYear(year))
		{
			monthReturn = 2;
		}
		else
		{
			monthReturn = 3;
		}
		break;
	case 3:
		monthReturn = 3;
		break;
	case 4:
		monthReturn = 6;
		break;
	case 5:
		monthReturn = 1;
		break;
	case 6:
		monthReturn = 4;
		break;
	case 7:
		monthReturn = 6;
		break;
	case 8:
		monthReturn = 2;
		break;
	case 9:
		monthReturn = 5;
		break;
	case 10:
		monthReturn = 0;
		break;
	case 11:
		monthReturn = 3;
		break;
	case 12:
		monthReturn = 5;
		break;
	}
	return monthReturn;
}

int dayOfWeek(int month, int day, int year) {
	// sum of date's day + the result of getMonthValue + getYearValue + getCenturyValue
	int day_of_week;
	day_of_week = getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year);
	// use the result of above divde 7, get the remainder
	day_of_week = day_of_week % 7;
	// the remainder will be the day of the week

	return day_of_week;
}

string dayOfWeek(int day) 
	// pre-condition: day has integer value 0, 1, 2, 3, 4, 5, or 6
	{
		day = day % 7;
		switch (day)
		{
		case 0:
			return "Sunday";
		case 1:
			return "Monday";
		case 2:
			return "Tuesday";
		case 3:
			return "Wednesday";
		case 4:
			return "Thursday";
		case 5:
			return "Friday";
		case 6:
			return "Saturday";
		}
	// post-condition: day has changed based on the index of dayName
}
	
// post-condition: the name of the day of week is returned as a std::. If day
//has value 0, then SUNDAY is returned; 1, then MONDAY is returned;and so on.

