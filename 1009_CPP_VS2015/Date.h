#pragma once
#ifndef  DATE_H
#define DATH_H

class Date {
	private:

	short days;
	short months;
	int years;

	public: 
		void setDays(short d);
		void setMonths(short m);
		void setYears(int y);

		short getDays();
		short getMonths();
		int getYears();

		Date(short d = 0, short m = 0, int y = 0);

		void print();

};
#endif // ! DATE_H
