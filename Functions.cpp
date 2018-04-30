/*
 * Functions.cpp
 *
 *  Created on: Apr 15, 2018
 *      Author: jerem
 */

#include <iostream>
#include <iomanip>
#include "Contact.h"
#include "ClientContact.h"

//*******************************************************
// Clear Cin
//*******************************************************
void clearCIN(void) {
	cin.clear();
	cin.ignore(32769,'\n');
}//ClearCin

//*******************************************************
// Contact Menu
//*******************************************************
void contactMenu(void) {
	cout << "1. Enter Contact Information" << endl;
	cout << "2. Display Contact Information" << endl;
	cout << "3. Edit Contact Information" << endl;
	cout << "4. Delete Contact Information" << endl;
	cout << "5. Exit the Program" << endl;
}//contactMenu

//*******************************************************
// Address Entry
//*******************************************************
void addAddress(Contact& c1)
{
	// Prompt for address line 1
	if( c1.getAddrLine1() != "<Unknown>")
		cout << c1.getFirstName() << " currently has " << c1.getAddrLine1() << " as the first line of their address." << endl;
	cout << "Enter the first line of your contact's street address (or 999 if blank): ";
	c1.setAddrLine1(cin);

	// Prompt for address line 2
	if( c1.getAddrLine2() != "<Unknown>")
		cout << c1.getFirstName() << " currently has " << c1.getAddrLine2() << " as the second line of their address." << endl;
	cout << "Enter the second line of your contact's street address (or 999 if blank): ";
	c1.setAddrLine2(cin);

	// Prompt for city
	if( c1.getCity() != "<Unknown>")
		cout << c1.getFirstName() << " currently has " << c1.getCity() << " as their city." << endl;
	cout << "Enter your contact's city (or 999 if blank): ";
	c1.setCity(cin);

	// Prompt for state
	Contact::State inState;
	do
	{
		if ( cin.fail() )
		{
			clearCIN();
			cout << "Invalid data entered. Enter your contact's State abbreviation [enter XX for blank]: ";
		}
		else
			cout << "Please enter your contact's State abbreviation: ";
		cin >> inState; // store state
	} while ( cin.fail() );
	c1.setState(inState);

	// Prompt for zip
	clearCIN();
	Contact::Zipcode inZip;
	do
	{
		if ( cin.fail() )
		{
			clearCIN();
			cout << "Invalid data entered. Enter your contact's ZIP Code in the form of NNNNN-NNNN or NNNNN [enter 99999 for blank]: ";
		}
		else
			cout << "Please enter your contact's ZIP Code in the form of NNNNN-NNNN or NNNNN: ";
		cin >> inZip; // store date
	} while ( cin.fail() );
	c1.setZip(inZip);
}// addAddress

//*******************************************************
// Birth Date Entry
//*******************************************************
void addBirthDate(Contact& c1)
{
	Date tmpDate;
	do
	{
		if ( cin.fail() )
		{
			cin.clear();
			cin.ignore(32764,'\n');
			cout << "Invalid data entered. Please enter your contact's birthdate in the form of MM/DD/YYYY (or 99/99/9999 if unknown): ";
		}
		else
		{
			if (c1.getBirthDate() != "<Unknown>")
				cout << c1.getFirstName() << " currently has " << c1.getBirthDate() << " as their birth date." << endl;
			cout << "Please enter your contact's birthdate in the form of MM/DD/YYYY: ";
		}

		cin >> tmpDate; // store date
	} while ( cin.fail() );
	c1.setBirthDate(tmpDate);

	// downcast pointer for Client Contact
	clearCIN();
	Contact * ptr = &c1;
	ClientContact *contactPtr = dynamic_cast < ClientContact * > (ptr);
	if (contactPtr != 0)
	{
		Date clientDate;
			do
			{
				if ( cin.fail() )
				{
					cin.clear();
					cin.ignore(32764,'\n');
					cout << "Invalid data entered. Please enter your client's first contact date in the form of MM/DD/YYYY (or 99/99/9999 if unknown): ";
				}
				else
				{
					if (contactPtr->getClientSinceDate() != "<Unknown>")
						cout << contactPtr->getFirstName() << " currently has " << contactPtr->getClientSinceDate() << " as their first contact date." << endl;
					cout << "Please enter your client's first contact date in the form of MM/DD/YYYY: ";
				}

				cin >> clientDate; // store date
			} while ( cin.fail() );
			contactPtr->setClientSinceDate(clientDate);
	}// end downcast client date entry

}// addBirthDate

//*******************************************************
// Email Entry
//*******************************************************
void addContactEmail(Contact& c1)
{
	Contact::Email tmpEmail;
	do
	{
		if ( cin.fail() )
		{
			cin.clear();
			cin.ignore(32764,'\n');
			cout << "Invalid data entered. Please enter your contact's email in the form of user@domain.tld (or 999@999.999 if unknown): ";
		}
		else
		{
			if (c1.getEmail() != "<Unknown>")
				cout << c1.getFirstName() << " currently has " << c1.getEmail() << " as their email." << endl;
			cout << "Please enter your contact's email in the form of user@domain.tld: ";
		}

		cin >> tmpEmail; // store date
	} while ( cin.fail() );
	//cout << "Email entered was " << tmpEmail.emailAddress << endl;
	c1.setEmail(tmpEmail);
}// addContactEmail

//*******************************************************
// Phone Entry
//*******************************************************
void addContactPhones(Contact& c1)
{
	// Prompt for home phone number
	PhoneNumber inHomePhone;
	do
	{
		if ( cin.fail() )
		{
			clearCIN();
			cout << "Invalid data entered. Enter your contact's phone number in the form of (NNN) NNN-NNNN [enter (999) 999-9999 for blank]: ";
		}
		else
		{
			if (c1.getHomePhone() != "<Unknown>")
				cout << c1.getFirstName() << " currently has " << c1.getHomePhone() << " as their home phone." << endl;
			cout << "Please enter your contact's home phone number in the form of (NNN) NNN-NNNN: ";
		}
		cin >> inHomePhone; // store date
	} while ( cin.fail() );
	c1.setHomePhone(inHomePhone);

	// Prompt for mobile phone number
	clearCIN();

	PhoneNumber inMobilePhone;
	do
	{
		if ( cin.fail() )
		{
			clearCIN();
			cout << "Invalid data entered. Enter your contact's phone number in the form of (NNN) NNN-NNNN [enter (999) 999-9999 for blank]: ";
		}
		else
		{
			if (c1.getMobilePhone() != "<Unknown>")
				cout << c1.getFirstName() << " currently has " << c1.getMobilePhone() << " as their mobile phone." << endl;
			cout << "Please enter your contact's mobile phone number in the form of (NNN) NNN-NNNN: ";
		}
		cin >> inMobilePhone; // store date
	} while ( cin.fail() );
	c1.setMobilePhone(inMobilePhone);

	// Prompt for work phone number
	clearCIN();

	PhoneNumber inWorkPhone;
	do
	{
		if ( cin.fail() )
		{
			clearCIN();
			cout << "Invalid data entered. Enter your contact's phone number in the form of (NNN) NNN-NNNN [enter (999) 999-9999 for blank]: ";
		}
		else
		{
			if (c1.getWorkPhone() != "<Unknown>")
				cout << c1.getFirstName() << " currently has " << c1.getWorkPhone() << " as their work phone." << endl;
			cout << "Please enter your contact's work phone number in the form of (NNN) NNN-NNNN: ";
		}
		cin >> inWorkPhone; // store date
	} while ( cin.fail() );
	c1.setWorkPhone(inWorkPhone);
}// addContactPhones


//*******************************************************
// Contact Edit Menu
//*******************************************************
void contactEditMenu(Contact& c1)
{
	char menuChoice;
	do {
		cout << endl;
		cout << "1. Enter Contact Birth Date" << endl;
		cout << "2. Enter Contact Phone(s)" << endl;
		cout << "3. Enter Contact Address" << endl;
		cout << "4. Enter Contact Email" << endl;
		cout << "5. Done editing" << endl;
		cout << "Please enter a menu choice: ";
		cin >> menuChoice;
		clearCIN();

		switch(toupper(menuChoice)) {
			case ('1'): {
				addBirthDate(c1);
				break;
			}//case 1
			case('2'): {
				addContactPhones(c1);
				break;
			}//case 2
			case('3'): {
				addAddress(c1);
				break;
			}//case 3
			case('4'): {
				addContactEmail(c1);
				break;
			}//case 4
			case('5'): {
				cout << endl << "Program is ending - Have a nice day!" << endl;
				break;
			}//case 5
			default:  {
				cout << "==========================================" << endl << endl;
				cout << "Invalid choice. Valid menu options are 1-5. " << endl << endl;
			}
		}//switch menuChoice

	} while ( menuChoice != '5' ); //while
}

//*******************************************************
// Contact Entry
//*******************************************************
Contact contactEntry()
{
	Contact *c1;

	int clientType;
	char typeAnswer;
	cout << "\nIs this contact a business Client (y/n): ";
	cin >> typeAnswer;

	clearCIN();
	if (toupper(typeAnswer) == 'Y')
		clientType = 2;
	if (toupper(typeAnswer) == 'N')
		clientType = 1;


	switch(clientType)
	{
		case(2):
			{ c1 = new ClientContact; break; }
		default:
			{ c1 = new Contact; }
	}

	//*******************************************************
	// Name Entry
	//*******************************************************
	//Prompt for entry of first name
	string inputName;
	cout << "Please enter your contact's first name: ";
	getline(cin, inputName);
	c1->setFirstName(inputName);

	// Prompt for entry of last name
	inputName="";
	cout << "Please enter your contact's last name: ";
	getline(cin, inputName);
	c1->setLastName(inputName);

	// Prompt for additional information
	contactEditMenu(*c1);

	return *c1;
} // contactEntry


//*******************************************************
// Display output
//*******************************************************
void displayContact(Contact c1)
{
	cout << endl;
	cout << setw(33) << left << "First Name" <<
			setw(33) << "Last Name" <<
			setw(13) << "Birth Date" <<
			setw(17) << "Home Phone" <<
			setw(17) << "Mobile Phone" <<
			setw(17) << "Work Phone" <<
			setw(30) << "Address Line 1" <<
			setw(30) << "Address Line 2" <<
			setw(20) << "City" <<
			setw(5)  << "State" <<
			setw(7)  << "ZIP" << endl;

	cout << setw(33) << left << "==========" <<
			setw(33) << "===========" <<
			setw(13) << "==========" <<
			setw(17) << "==========" <<
			setw(17) << "============" <<
			setw(17) << "==========" <<
			setw(30) << "==========" <<
			setw(30) << "==========" <<
			setw(20) << "==========" <<
			setw(5)  << "====" <<
			setw(7)  << "=====" <<	endl;

	cout << setw(33) << left << c1.getFirstName() <<
			setw(33) << c1.getLastName() <<
			setw(13) << c1.getBirthDate() <<
			setw(17) << c1.getHomePhone() <<
			setw(17) << c1.getMobilePhone() <<
			setw(17) << c1.getWorkPhone() <<
			setw(30) << c1.getAddrLine1() <<
			setw(30) << c1.getAddrLine2() <<
			setw(20) << c1.getCity() <<
			setw(5)  << c1.getState() <<
			setw(7)  << c1.getZip() << endl << endl;


} // displayContact
