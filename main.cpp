//============================================================================
// Name        : CS2Project_ContactManager.cpp
// Author      : Jeremy Norvell
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Contact.h"
#include "Functions.h"
#include "ContactList.h"
using namespace std;

int main() {
	char menuChoice;
	string firstName, lastName;
	Contact cont1;
	ContactList list;

	cout << "Welcome to the Contact Management System" << endl;
	cout << "========================================" << endl;

	do {

			contactMenu();
			cout << "Please enter a menu choice: ";
			cin >> menuChoice;
			clearCIN();

			switch(toupper(menuChoice)) {
				case ('1'): {
					cont1=contactEntry();
					break;
				}//case 1
				case('2'): {
					displayContact(cont1);
					break;
				}//case 2
				case('3'):{
					cout << "Enter the name of the contact you would like to edit\nFirst: ";
					cin >> firstName;
					cout << "Last: ";
					cin >> lastName;

					list.editContact(firstName, lastName);
					list.editContact(firstName, lastName);

					//cont1 = searchforContact(firstName, lastName);
					//editContact(cont1);

					break;
				}
				case('4'): {
					cout << "Enter the name of the contact you would like to delete\nFirst: ";
					cin >> firstName;
					cout << "Last: ";
					cin >> lastName;

					list.deleteContact(firstName, lastName);

					//cont1 = searchforContact(firstName, lastName);

					list.deleteContact(firstName, lastName);		//cont1 = searchforContact(firstName, lastName);

					//deleteContact(cont1);

					break;
				}
				case('5'): {
					cout << endl << "Program is ending - Have a nice day!" << endl;
					break;
				}//case 7
				default:  {
					cout << "========================================" << endl << endl;
					cout << "Invalid choice. Valid menu options are 1-5. " << endl << endl;
				}
			}//switch menuChoice

		} while ( menuChoice != '5' ); //while

		return 0;

	cout << "Program Ending. Have a nice day." << endl; // prints Program Ending. Have a nice day.
	return 0;
}
