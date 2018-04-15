/*
 * Phone.h
 *
 *  Created on: Apr 15, 2018
 *      Author: jerem
 */

#ifndef PHONENUMBER_H_
#define PHONENUMBER_H_

#include <iostream>
using namespace std;

class PhoneNumber
{
	// overloaded input and output operators
	friend ostream &operator<<( ostream&, const PhoneNumber& );
	friend istream &operator>>( istream&, PhoneNumber& );
private:
	string number;   // hold phone number
public:
	PhoneNumber(); // constructor
	// Accessors
	const string getPhoneNumber () const;

}; // end class PhoneNumber

#endif /* PHONENUMBER_H_ */


