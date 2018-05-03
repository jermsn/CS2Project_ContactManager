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
public:
	// Structures
	struct State
	{	char stateAbbrev[3];	};
	struct Zipcode
	{	string zip;	};
	struct Email
	{	string emailAddress;	};
	// Constructor
	Contact();
	// Destructor
	virtual ~Contact() {}
	// Accessors
	const char * getFirstName() const;	// Return first name of contact
	const char * getLastName() const; 	// Return last name of contact
	const string getBirthDate() const;	// Return contact birth date
	const string getHomePhone() const;	// Return home phone
	const string getMobilePhone() const;// Return mobile phone
	const string getWorkPhone() const;	// Return work phone
	const string getAddrLine1() const;	// Return address line 1
	const string getAddrLine2() const;	// Return address line 2
	const string getCity() const;		// Return city
	const string getState() const;		// Return state
	const string getZip() const; 		// Return ZIP code
	const string getEmail() const; 		// Return Email
	virtual int getTypeOfContact() const;
	// Mutators
	void setFirstName(string);			// Set first name of contact
	void setLastName(string);			// Set last name of contact
	void setBirthDate(Date);			// Set birth date
	void setHomePhone(PhoneNumber);		// Set home phone
	void setMobilePhone(PhoneNumber);	// Set mobile phone
	void setWorkPhone(PhoneNumber);		// Set work phone
	void setAddrLine1(string);			// Set address line 1
	void setAddrLine1(istream&);		// Set address line 1 - stream input
	void setAddrLine2(string);			// Set address line 2
	void setAddrLine2(istream&);		// Set address line 2 - stream input
	void setCity(string);				// Set city
	void setCity(istream&);				// Set city - stream input
	void setState(char*);				// Set state
	void setState(State);				// Set state - copy
	void setZip(Zipcode);				// Set ZIP code
	void setEmail(Email);				// Set Email Address
	void resetContact();
	// Friends
	friend ostream &operator << (ostream &, const State &);
	friend istream &operator >> (istream &, State &);
	friend ostream &operator << (ostream &, const Zipcode &);
	friend istream &operator >> (istream &, Zipcode &);
	friend ostream &operator << (ostream &, const Email &);
	friend istream &operator >> (istream &, Email &);
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
	State state;			// State of mailing address
	Zipcode zip;			// Zip code of mailing address
	Email email;			// Email of the contact

	int typeOfContact;		// Discern type of contact
};


#endif /* CONTACT_H_ */
