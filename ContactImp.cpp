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



