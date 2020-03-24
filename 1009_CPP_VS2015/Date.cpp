#include <iostream>
#include <iomanip> 
#include "Date.h"
using namespace std;

Date::Date(short d, short m, int y)
{
	setDays(d);
	setMonths(m);
	setYears(y);

}

void Date::setDays(short d) //days
{
	if (d >= 1 && d <= 31)
	{
		days = d;
	}
//else days = default value = 0
}

short Date::getDays() 
{
	return days;
}

void Date::setMonths(short m) 
{
	if (m >= 1 && m <= 12)
	{
		months = m;
	}

}

short Date::getMonths()
{
	return months;
}

void Date::setYears(int y) 
{
	years = y;
}

int Date::getYears() 
{
	return years;
}

void Date::print()
{
	cout << setfill('0') << setw(2) << getDays() << "/"
		<< setw(2) << getMonths() << "/"
		<< setw(4) << getYears();
}
