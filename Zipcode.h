/*
 * Zipcode.h
 *
 *  Created on: Apr 18, 2018
 *      Author: student
 */

#ifndef ZIPCODE_H_
#define ZIPCODE_H_

#include <iostream>
using namespace std;

class Zipcode
{
	// Friends
	friend ostream &operator << (ostream &, const Zipcode &);
	friend istream &operator >> (istream &, Zipcode &);
private:
	string zip;						// ZIP code
public:
	// Accessor
	const string getPhoneNumber () const;
};


#endif /* ZIPCODE_H_ */
