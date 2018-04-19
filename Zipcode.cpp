/*
 * Zipcode.cpp
 *
 *  Created on: Apr 18, 2018
 *      Author: student
 */

#include <iostream>
#include <string>
#include "Zipcode.h"

using namespace std;

// default constructor
Zipcode::Zipcode():
		zip("99999")
{
	// empty body
} // end Zipcode constructor

//****************************************************************
//	Accessor for Zip
//****************************************************************
const string Zipcode::getZip() const
{
	string tmpStr;
	if (zip != "999")
		tmpStr = zip;
	else
		tmpStr = "<Unknown>";

	return tmpStr;
}

//****************************************************************
//	Stream input for ZIP code
//****************************************************************
istream &operator>>( istream &input, Zipcode &inZip)
{
	const int LEN=13;
	char tempIn[LEN];

	//cout << "Your input is " << input.gcount() << " characters long." << endl;

	input.get( tempIn, LEN );
	if (!( input.gcount() == 10 || input.gcount() == 5 ) ) 		// case must be 99999 or 99999-9999
	{
		cout << "Invalid length: " << input.gcount() << endl;
		input.clear( ios::failbit );
	}	// or set bad bit
	else 														// proper count of characters - checking format
	{
		for(int i=0; i < 11; i++)
		{
			if ( (i >= 0 && i <= 4) && !isdigit(tempIn[i]) ) 		// case input must be numeric
			{
				cout << "Invalid character " << tempIn[i] << " at position " << i << endl;
				input.clear( ios::failbit ); 						// set bad bit
			}
			if ( i == 5 && !(tempIn[i] == 55 || tempIn[i] == 32 ))	// case 6th char is dash or space
			{
				cout << "Invalid character " << tempIn[i] << " at position " << i << endl;
				input.clear( ios::failbit ); 						// set bad bit
			}
			if ( (i >= 6 && i <= 8) && !isdigit(tempIn[i]) )		// case chars 7-10 must be numeric
			{
				cout << "Invalid character " << tempIn[i] << " at position " << i << endl;
				input.clear( ios::failbit ); 						// set bad bit
			}
		}
	}
	return input;
}

