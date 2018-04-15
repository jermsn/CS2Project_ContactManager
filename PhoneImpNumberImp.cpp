/*
 * PhoneImp.cpp
 *
 *  Created on: Apr 15, 2018
 *      Author: jerem
 */

#include <iostream>
#include <string>
#include "PhoneNumber.h"

using namespace std;

// default constructor
PhoneNumber::PhoneNumber():
		number("(999) 999-9999")
{
	// empty body
} // end Complex constructor

//****************************************************************
//	Accessor for PhoneNumber
//****************************************************************
const string PhoneNumber::getPhoneNumber () const
{
	string tmpPhone;
	if ( number != "(999) 999-9999")
		tmpPhone = number;
	else
		tmpPhone = "<Unknown>";

	return tmpPhone;
}

// overloaded output (<<) operator
ostream &operator<<( ostream &output, const PhoneNumber &pN )
{
	output << pN.number;
	return output;
}

// overloaded input (>>) operator
istream &operator>>( istream &input, PhoneNumber &pN)
{
	const int LEN=16;
	char tempIn[LEN];

	input.get( tempIn, LEN );
	if ( input.gcount() != 14 ) 				// case more or less than 14 characters
		input.clear( ios::failbit ); 			// set bad bit
	else 										// proper count of characters - checking format
	{
		for( int i = 0; i < 14; i++)
		{
			if (i == 0 && tempIn[i] != '(') 							// case input doesn't start with (
				input.clear( ios::failbit ); 							// set bad bit
			else if (i == 1 && !(tempIn[i] >= 50 && tempIn[i] <=57)) 	// case area code cant start with 0 or 1; compared against ascii
				input.clear( ios::failbit ); 							// set bad bit
			else if ((i > 1 && i < 4) && !(isdigit(tempIn[i]))) 		// case must be a number
				input.clear( ios::failbit ); 							// set bad bit
			else if (i == 4 && tempIn[i] != ')') 						// case area code doesn't end with )
				input.clear( ios::failbit ); 							// set bad bit
			else if (i == 5 && tempIn[i] != ' ')						// case no space after area code
				input.clear( ios::failbit ); 							// set bad bit
			else if (i == 6 && !(tempIn[i] >= 50 && tempIn[i] <=57))	// case prefix cant start with 0 or 1; compared against ascii
				input.clear( ios::failbit ); 							// set bad bit
			else if ((i > 6 && i < 9) && !(isdigit(tempIn[i])))			// case characters 2-3 of prefix must be a number
				input.clear( ios::failbit ); 							// set bad bit
			else if (i == 9 && !(tempIn[i] == '-')) 					// case prefix must be followed with a dash
				input.clear( ios::failbit ); 							// set bad bit
			else if ((i >= 10 && i <=13) && i <= !(isdigit(tempIn[i]))) // case main number must be all numeric
				input.clear( ios::failbit ); 							// set bad bit
		}
	} // end character count else

	if (!cin.fail())													// Assign input to phone number if formatted correctly
	{
		string tempStr(tempIn);
		pN.number = tempStr;
	}

	return input;
}




