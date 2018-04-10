/*
 * Contact.h
 *
 *  Created on: Apr 9, 2018
 *      Author: student
 */

#ifndef CONTACT_H_
#define CONTACT_H_

using namespace std;

class Contact
{
private:
	char firstName[30]; 	// c-string of first name
	char lastName[30];		// c-string of last name
	string birthDate;		// c-string of birth date, formatted mm/dd/yyyy
	string homePhone;		// c-string of home phone, formated (NNN) NNN-NNNN
	string mobilePhone;		// c-string of mobile phone, formated (NNN) NNN-NNNN
	string workPhone;		// c-string of work phone, formated (NNN) NNN-NNNN
	string addrLine1;		// first line of mailing address
	string addrLine2;		// second line of mailing address
	string city;			// city of mailing address
	string state;			// state of mailing address
	string zip;				// zip code of mailing address
public:
	char[30] getFirstName() const;	// return first name of contact
	char[30] getLastName() const; 	// return last name of contact
};




#endif /* CONTACT_H_ */
