/*
 * Date.h
 *
 *  Created on: Apr 15, 2018
 *      Author: jerem
 */

#ifndef DATE_H_
#define DATE_H_

#include <iostream>

using namespace std;

class Date
{
	// Friends
	friend ostream &operator << (ostream &, const Date &);
	friend istream &operator >> (istream &, Date &);
private:
	int month;
	int day;
	int year;
public:
	// Accessors
	const int getMonth() const;
	const int getDay() const;
	const int getYear() const;
	// Mutators
	void setMonth(int, int, int);
	void setDay(int, int, int);
	void setYear(int, int, int);
	// Exception classes
	class invalidMonth{};
	class invalidDay{};
	class invalidYear{};
};



#endif /* DATE_H_ */
