/*
 * Functions.cpp
 *
 *  Created on: Apr 15, 2018
 *      Author: jerem
 */

#include <iostream>
#include <iomanip>
#include "Contact.h"

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
	cout << "3. Exit the Program" << endl;
}//contactMenu

//*******************************************************
// Contact Entry
//*******************************************************
Contact contactEntry()
{
	Contact c1;

	//*******************************************************
	// Name Entry
	//*******************************************************
	//Prompt for entry of first name
	string inputName;
	cout << "Please enter your contact's first name: ";
	getline(cin, inputName);
	c1.setFirstName(inputName);

	// Prompt for entry of last name
	inputName="";
	cout << "Please enter your contact's last name: ";
	getline(cin, inputName);
	c1.setLastName(inputName);

	//*******************************************************
	// Birth Date Entry
	//*******************************************************
	// Prompt for birthdate
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
			cout << "Please enter your contact's birthdate in the form of MM/DD/YYYY: ";
		cin >> tmpDate; // store date
	} while ( cin.fail() );
	c1.setBirthDate(tmpDate);

	//*******************************************************
	// Phone Entry
	//*******************************************************
	// Prompt for home phone number
	clearCIN();

	PhoneNumber inHomePhone;
	do
	{
		if ( cin.fail() )
		{
			clearCIN();
			cout << "Invalid data entered. Enter your contact's phone number in the form of (NNN) NNN-NNNN [enter (999) 999-9999 for blank]: ";
		}
		else
			cout << "Please enter your contact's home phone number in the form of (NNN) NNN-NNNN: ";
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
			cout << "Please enter your contact's mobile phone number in the form of (NNN) NNN-NNNN: ";
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
			cout << "Please enter your contact's work phone number in the form of (NNN) NNN-NNNN: ";
		cin >> inWorkPhone; // store date
	} while ( cin.fail() );
	c1.setWorkPhone(inWorkPhone);

	return c1;
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
			setw(17) << "Work Phone" << endl;

	cout << setw(33) << left << "==========" <<
			setw(33) << "===========" <<
			setw(13) << "==========" <<
			setw(17) << "==========" <<
			setw(17) << "============" <<
			setw(17) << "==========" << endl;

	cout << setw(33) << left << c1.getFirstName() <<
			setw(33) << c1.getLastName() <<
			setw(13) << c1.getBirthDate() <<
			setw(17) << c1.getHomePhone() <<
			setw(17) << c1.getMobilePhone() <<
			setw(17) << c1.getWorkPhone() << endl << endl;

//	cout << endl;
//	cout << "First name, in corrected case is: " << c1.getFirstName() << endl;
//	cout << "Last name, in corrected case is: " << c1.getLastName() << endl;
//	cout << "Birthdate, if known, is: " << c1.getBirthDate() << endl;
//	cout << "Home phone number is: " << c1.getHomePhone() << endl;
//	cout << "Mobile phone number is: " << c1.getMobilePhone() << endl;
//	cout << "Work phone number is: " << c1.getWorkPhone() << endl;
//	cout << endl;
} // displayContact


