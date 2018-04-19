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
	birthDate.setMonth(99, 99, 9999);
	birthDate.setDay(99, 99, 9999);
	birthDate.setYear(99, 99, 9999);
	addrLine1 = "999";
	addrLine2 = "999";
	city = "999";
	zip = "99999";
}

//****************************************************************
//	Stream input for ZIP code
//****************************************************************
istream &operator>>( istream &input, Contact::Zipcode &inZip)
{
	const int LEN=13;
	char tempIn[LEN];

	cout << "Your input is " << input.gcount() << " characters long." << endl;

	input.get( tempIn, LEN );
	if (!( input.gcount() == 11 || input.gcount() == 6 ) ) 		// case must be 99999 or 99999-9999
		input.clear( ios::failbit ); 							// or set bad bit
	else 														// proper count of characters - checking format
	{
		for(int i=0; i < 11; i++)
		{
			if ( (i >= 0 && i <= 4) && !isdigit(tempIn[i]) ) 		// case input must be numeric
				input.clear( ios::failbit ); 						// set bad bit
			if ( i >= 5 && !(tempIn[i] == 55 || tempIn[i] == 32 ))	// case 6th char is dash or space
				input.clear( ios::failbit ); 						// set bad bit
			if ( (i >= 6 && i <= 8) && !isdigit(tempIn[i]) )		// case chars 7-10 must be numeric
				input.clear( ios::failbit ); 						// set bad bit
		}
	}
	return input;
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

	if ( birthDate.getYear() != 9999)
		tmpStr = to_string(birthDate.getMonth()) + "/" + to_string(birthDate.getDay()) + "/" + to_string(birthDate.getYear());
	else
		tmpStr = "<Unknown>";

	return tmpStr;
}

//****************************************************************
//	Accessor for Home Phone
//****************************************************************
string Contact::getHomePhone() const
{
	return homePhone.getPhoneNumber();
}

//****************************************************************
//	Accessor for Mobile Phone
//****************************************************************
string Contact::getMobilePhone() const
{
	return mobilePhone.getPhoneNumber();
}

//****************************************************************
//	Accessor for Work Phone
//****************************************************************
string Contact::getWorkPhone() const
{
	return workPhone.getPhoneNumber();
}

//****************************************************************
//	Accessor for Address Line 1
//****************************************************************
string Contact::getAddrLine1() const
{
	string tmpStr;
	if (addrLine1 != "999")
		tmpStr = addrLine1;
	else
		tmpStr = "<Unknown>";

	return tmpStr;
}

//****************************************************************
//	Accessor for Address Line 2
//****************************************************************
string Contact::getAddrLine2() const
{
	string tmpStr;
	if (addrLine2 != "999")
		tmpStr = addrLine2;
	else
		tmpStr = "<Unknown>";

	return tmpStr;
}

//****************************************************************
//	Accessor for City
//****************************************************************
string Contact::getCity() const
{
	string tmpStr;
	if (city != "999")
		tmpStr = city;
	else
		tmpStr = "<Unknown>";

	return tmpStr;
}


//****************************************************************
//	Accessor for State
//****************************************************************
string Contact::getState() const
{
	string tmpStr;
	if (state != "999")
		tmpStr = state;
	else
		tmpStr = "<Unknown>";

	return tmpStr;
}

//****************************************************************
//	Accessor for Zip
//****************************************************************
string Contact::getZip() const
{
	string tmpStr;
	if (zip != "999")
		tmpStr = zip;
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
//	Mutator for home phone
//****************************************************************
void Contact::setHomePhone(PhoneNumber inputPhone)
{
	homePhone = inputPhone;
}

//****************************************************************
//	Mutator for mobile phone
//****************************************************************
void Contact::setMobilePhone(PhoneNumber inputPhone)
{
	mobilePhone = inputPhone;
}

//****************************************************************
//	Mutator for work phone
//****************************************************************
void Contact::setWorkPhone(PhoneNumber inputPhone)
{
	workPhone = inputPhone;
}

//****************************************************************
//	Mutator for Address Line 1
//****************************************************************
void Contact::setAddrLine1(string inAddrLine1)
{
	//cout << "Assigning " << inAddrLine1 << " to addr" << endl;
	addrLine1 = inAddrLine1;
}

//****************************************************************
//	Mutator for Address Line 2
//****************************************************************
void Contact::setAddrLine2(string inAddrLine2)
{
	addrLine2 = inAddrLine2;
}

//****************************************************************
//	Mutator for City
//****************************************************************
void Contact::setCity(string inCity)
{
	city = inCity;
}

//****************************************************************
//	Mutator for State
//****************************************************************
void Contact::setState(string inState)
{
	state = inState;
}

//****************************************************************
//	Mutator for ZIP Code
//****************************************************************
void Contact::setZip(Contact::Zipcode inZip)
{
	zip = inZip;
}
