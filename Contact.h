/*
 * Contact.h
 *
 *  Created on: Apr 9, 2018
 *      Author: student
 */

#include "Date.h"
#include "PhoneNumber.h"

#ifndef CONTACT_H_
#define CONTACT_H_

using namespace std;

class Contact
{
private:
	char firstName[30];		// First name
	char lastName[30];		// Last name
	Date birthDate;			// Birth date, formatted mm/dd/yyyy
	PhoneNumber homePhone;	// Home phone, formated (NNN) NNN-NNNN
	PhoneNumber mobilePhone;// Mobile phone, formated (NNN) NNN-NNNN
	PhoneNumber workPhone;	// Work phone, formated (NNN) NNN-NNNN
	string addrLine1;		// First line of mailing address
	string addrLine2;		// Second line of mailing address
	string city;			// City of mailing address
	string state;			// State of mailing address
	string zip;				// Zip code of mailing address
public:
	// Constructor
	Contact();
	// Accessors
	const char * getFirstName() const;	// Return first name of contact
	const char * getLastName() const; 	// Return last name of contact
	string getBirthDate() const;		// Return contact birth date
	string getHomePhone() const; 		// Return home phone
	string getMobilePhone() const;		// Return mobile phone
	string getWorkPhone() const;		// Return work phone
	string getAddrLine1() const;		// Return address line 1
	string getAddrLine2() const;		// Return address line 2
	string getCity() const;				// Return city
	string getState() const;			// Return state
	string getZip() const;				// Return ZIP
	// Mutators
	void setFirstName(string);			// Set first name of contact
	void setLastName(string);			// Set last name of contact
	void setBirthDate(Date);			// Set birth date
	void setHomePhone(PhoneNumber);		// Set home phone
	void setMobilePhone(PhoneNumber);	// Set mobile phone
	void setWorkPhone(PhoneNumber);		// Set work phone
	void setAddrLine1(string);			// Set address line 1
	void setAddrLine2(string);			// Set address line 2
	void setCity(string);				// Set city
	void setState(string);				// Set state
	void setZip(string);				// Set ZIP
};


#endif /* CONTACT_H_ */
