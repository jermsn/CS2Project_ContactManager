/*
 * Contact.h
 *
 *  Created on: Apr 9, 2018
 *      Author: student
 */

#ifndef CONTACT_H_
#define CONTACT_H_

using namespace std;

class Date
{
	// Friends
	friend ostream &operator << (ostream &, const Date &);
	friend istream &operator >> (istream &, Date &);
public:
	int month;
	int day;
	int year;
};

class Contact
{
private:
	char firstName[30];		// First name
	char lastName[30];		// Last name
	Date birthDate;			// Birth date, formatted mm/dd/yyyy
	string homePhone;		// Home phone, formated (NNN) NNN-NNNN
	string mobilePhone;		// Mobile phone, formated (NNN) NNN-NNNN
	string workPhone;		// Work phone, formated (NNN) NNN-NNNN
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
	string getHomePHone() const; 	// Return home phone
	// Mutators
	void setFirstName(string);		// Set first name of contact
	void setLastName(string);		// Set last name of contact
	void setBirthDate(Date);		// Set birth date
	void setHomePHone(string);		// Set home phone
	// Exception classes
	class invalidMonth{};
};


#endif /* CONTACT_H_ */
