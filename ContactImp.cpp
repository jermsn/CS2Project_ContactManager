/*
 * ContactImp.cpp
 *
 *  Created on: Apr 9, 2018
 *      Author: student
 */

#include <iostream>
#include <string.h>
#include "Contact.h"

using namespace std;

//****************************************************************
//	Constructor for base class
//****************************************************************
Contact::Contact()
{
	for(int f=0; f<30; f++)
		firstName[f]=' ';
	for(int l=0; l<30; l++)
		lastName[l]=' ';
	birthDate.day=99;
	birthDate.month=99;
	birthDate.year=9999;
}

//****************************************************************
//	Accessor for First Name
//****************************************************************
const char * Contact::getFirstName() const
{
	return firstName;
}

//****************************************************************
//	Accessor for Last Name
//****************************************************************
const char * Contact::getLastName() const
{
	return lastName;
}

//****************************************************************
//	Accessor for Birth Date
//****************************************************************
string Contact::getBirthDate() const
{
	string tmpStr;

	if ( birthDate.year != 9999)
		tmpStr = to_string(birthDate.month) + "/" + to_string(birthDate.day) + "/" + to_string(birthDate.year);
	else
		tmpStr = "<Unknown>";

	return tmpStr;
}

//****************************************************************
//	Mutator for First Name
//	Makes first character upper, and all other characters
//	lower case
//****************************************************************
void Contact::setFirstName(string inFN)
{
	char tmpName[30];
	strcpy(tmpName,inFN.c_str());

	for (int i=0; i<30; i++)
	{
		if(i==0)
			firstName[i] = toupper(tmpName[i]);
		else
			firstName[i] = tolower(tmpName[i]);
	}
}

//****************************************************************
//	Mutator for Last Name
//	Makes first character upper, and all other characters
//	lower case
//****************************************************************
void Contact::setLastName(string inLN)
{
	char tmpName[30];
	strcpy(tmpName,inLN.c_str());

	for (int i=0; i<30; i++)
	{
		if(i==0)
			lastName[i] = toupper(tmpName[i]);
		else
			lastName[i] = tolower(tmpName[i]);
	}
}

//****************************************************************
//	Mutator for birth date
//****************************************************************
void Contact::setBirthDate(Date inputDate)
{
	birthDate = inputDate;
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
	int inNum;
	char temp; 								// temporary variable used to read through input

	if( isdigit(input.peek()) )
			input >> inNum;					// read first number
	else
	{
		input >> temp;
		input.clear( ios::failbit );
	}

	if( input.peek() != '/' )
		input.clear( ios::failbit ); 		// first date separator was not correct; set bad bit
	else
	{
		dt.month = inNum;					// assign initial number to month
		input >> temp;						// read date separator into temp variable
		input >> inNum;						// read second number


		if(input.peek() == '/')
		{
			dt.day = inNum;					// assign second number to day
			input >> temp;
			input >> dt.year;
		}
		else
			input.clear( ios::failbit );	// second date separator was not correct; set bad bit
	}

	if(!( dt.month > 0 && dt.month < 13))
		input.clear( ios::failbit );
		//throw invalidMonth;
	if(!( dt.day > 0 && dt.day < 32))
		input.clear( ios::failbit );
	if(!( dt.year > 1900 && dt.year < 2100))
		input.clear( ios::failbit );

	return input;
}



