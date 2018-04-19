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

	// Prompt for address line 1
	cout << "Enter the first line of your contact's street address (or 999 if blank): ";
	string tmpA1;
	getline(cin, tmpA1);
	c1.setAddrLine1(tmpA1);

	// Prompt for address line 2
	cout << "Enter the second line of your contact's street address (or 999 if blank): ";
	string tmpA2;
	getline(cin, tmpA2);
	c1.setAddrLine2(tmpA2);

	// Prompt for city
	cout << "Enter your contact's city (or 999 if blank): ";
	string tmpCity;
	getline(cin, tmpCity);
	c1.setCity(tmpCity);

	// Prompt for state
	cout << "Enter your contact's state (or 999 if blank): ";
	string tmpState;
	getline(cin, tmpState);
	c1.setState(tmpState);

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


