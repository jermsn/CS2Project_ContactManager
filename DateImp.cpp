/*
 * DateImp.cpp
 *
 *  Created on: Apr 15, 2018
 *      Author: jerem
 */

#include <iostream>
#include <string.h>
#include "Date.h"

//****************************************************************
//	Accessor for Month
//****************************************************************
const int Date::getMonth() const
{
	return month;
}

//****************************************************************
//	Accessor for Day
//****************************************************************
const int Date::getDay() const
{
	return day;
}

//****************************************************************
//	Accessor for Year
//****************************************************************
const int Date::getYear() const
{
	return year;
}

//****************************************************************
//	Mutator for Day
//	Validates month is between 1 and 12, or throws an error
//****************************************************************
void Date::setMonth(int inMonth, int inDay, int inYear)
{
	if( inMonth > 0 && inMonth < 13 )	// check for month 1-12
		month = inMonth;
	// check for sentinel
	else if( inMonth == 99 && inDay == 99 && inYear == 9999 )
		month = inMonth;
	else
		throw invalidMonth();
}

//****************************************************************
//	Mutator for Month
//	Validates number of days are appropriate for the Month & Year
//****************************************************************
void Date::setDay(int inMonth, int inDay, int inYear)
{
	if(	( 	inMonth == 1  || 		// Case 31-day months
			inMonth == 3  ||
			inMonth == 5  ||
			inMonth == 7  ||
			inMonth == 8  ||
			inMonth == 10 ||
			inMonth == 12 )
			&&
		 ( inDay > 0 && inDay < 32 )// Must be 1 to 31 days
		)
		day = inDay;
	else if( ( 	inMonth == 4  ||	// Case 30-day months
				inMonth == 6  ||
				inMonth == 9  ||
				inMonth == 11)
				&&
			  ( inDay > 0 && inDay < 31)// Must be 1 to 30 days
		    )
		day = inDay;
	else if( ( inMonth == 2 )		// Case February leap year
			&& ( inYear%4 == 0)		// Year divisible by 4
			&& ( inDay > 0 && inDay < 30) // Must be 1 to 29 days
			)
		day = inDay;
	else if( ( inMonth == 2)		// Case February not leap year
			&& ( inYear%4 != 0)		// Year not divisible by 4
			&& ( inDay > 0 && inDay < 29) // Must be 1 to 29 days
			)
		day = inDay;
	// check for sentinel
	else if( inMonth == 99 && inDay == 99 && inYear == 9999 )
		day = inDay;
	else
		throw invalidDay();
}

//****************************************************************
//	Mutator for Year
//	Year is between 1900 and 2020
//****************************************************************
void Date::setYear(int inMonth, int inDay, int inYear)
{
	if( inYear > 1900 && inYear < 2020 )// check for valid years
		year = inYear;
	// check for sentinel
	else if( inMonth == 99 && inDay == 99 && inYear == 9999 )
		year = inYear;
	else
		throw invalidYear();
}

//****************************************************************
//	Stream output for dates
//****************************************************************
ostream &operator<<( ostream &output, const Date &dt )
{
	output << dt.month << "/" << dt.day << "/" << dt.year;
	return output;
}

//****************************************************************
//	Stream input and validation for dates
//	enforces date input in MM/DD/YYYY format
//****************************************************************
istream &operator>>( istream &input, Date &dt)
{
	int inMonth;							// temporary variable used to store month
	int inDay;								// temporary variable used to store day
	int inYear;								// temporary variable used to store year
	char temp; 								// temporary variable used to read through input

	if( isdigit(input.peek()) )
			input >> inMonth;				// read first number into month variable
	else
	{
		//input >> temp;
		input.clear( ios::failbit );
	}

	if( input.peek() != '/' )
		input.clear( ios::failbit ); 		// first date separator was not correct; set bad bit
	else
	{
		input >> temp;						// read date separator into temp variable
		input >> inDay;						// read second number into day variable

		if(input.peek() == '/')
		{
			input >> temp;
			input >> inYear;				// read final number into year variable
		}
		else
			input.clear( ios::failbit );	// second date separator was not correct; set bad bit
	}

	try										// tests input for valid values
	{
		dt.setMonth(inMonth, inDay, inYear);
		dt.setDay(inMonth, inDay, inYear);
		dt.setYear(inMonth, inDay, inYear);
	}

	catch (Date::invalidMonth&)				// Found invalid month
	{
		input.clear( ios::failbit );
		cout << "Error: A valid month is between 1 and 12, or 99 for blank.\n";
	}

	catch (Date::invalidDay&)				// Found invalid day
	{
		input.clear( ios::failbit );
		cout << "Error: A valid day is between 1-28,29,30 or 31 (dependent on month), or 99 for blank.\n";
	}

	catch (Date::invalidYear&)				// Found invalid year
	{
		input.clear( ios::failbit );
		cout << "Error: A valid year is between 1900 and 2020, or 9999 for blank.\n";
	}

	return input;
}


