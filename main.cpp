//============================================================================
// Name        : CS2Project_ContactManager.cpp
// Author      : Jeremy Norvell
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Contact.h"
using namespace std;

int main() {
	Contact c1;

	// Prompt for entry of first name
	string inputName;
	cout << "Please enter your contact's first name: ";
	getline(cin, inputName);
	c1.setFirstName(inputName);

	// Prompt for entry of last name
	inputName="";
	cout << "Please enter your contact's last name: ";
	getline(cin, inputName);
	c1.setLastName(inputName);

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


	cout << "First name, in corrected case is: " << c1.getFirstName() << endl;
	cout << "Last name, in corrected case is: " << c1.getLastName() << endl;
	cout << "Birthdate, if known, is: " << c1.getBirthDate() << endl;

	cout << "Program Ending. Have a nice day." << endl; // prints Program Ending. Have a nice day.
	return 0;
}
