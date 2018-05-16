//============================================================================
// Name        : CS2Project_ContactManager.cpp
// Author      : Jeremy Norvell
// Version     :
// Copyright   : Your copyright notice
// Description : Contact Manager
//============================================================================

#include <iostream>
#include <fstream>
#include "Contact.h"
#include "Functions.h"
#include "ContactList.h"
using namespace std;

int main() {
	char menuChoice;
	string firstName, lastName;
	Contact* cont1;
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
					cont1 = contactEntry();
					list.appendNode(cont1);
					cont1 = nullptr;
					break;
				}//case 1
				case('2'): {
					if (!list.empty())
						{ list.displayList();	}
					else
						{ cout << endl << "No contact created yet." << endl << endl;; }
					break;
				}//case 2
				case('3'):{
					cout << "Enter the name of the contact you would like to edit\nFirst: ";
					cin >> firstName;
					cout << "Last: ";
					cin >> lastName;

					cont1 = list.searchForContact(firstName, lastName);
					if(cont1 == nullptr)
						{ cout << "\nThere is no contact of that name to edit." << endl << endl; }
					else
						{ contactEditMenu( cont1 );	}
					break;
				}
				case('4'): {
					cout << "Enter the name of the contact you would like to delete\nFirst: ";
					cin >> firstName;
					cout << "Last: ";
					cin >> lastName;

					cont1 = list.searchForContact(firstName, lastName);
					if(list.searchForContact(firstName, lastName) == nullptr)
						{ cout << "\nThere is no contact of that name to delete." << endl << endl; }
					else
						{ list.deleteNode(cont1);	}
					break;
				}
				case('5'): {
					cout << "\nSaving your contacts to the file 'contacts.bin'." << endl << endl;

					fstream outContacts( "contacts.bin", ios::out | ios::binary );
					// exit program if fstream cannot open file
					if ( !outContacts )
						{ cout << "Error: 'contacts.bin' could not be opened." << endl; } // end if
					else
						{ list.writeContacts(outContacts); } // output contact records to file
					outContacts.close();
					break;
				}//case 5
				case('6'): {
					cout << endl << "Program is ending - Have a nice day!" << endl;
					break;
				}//case 6
				default:  {
					cout << "========================================" << endl << endl;
					cout << "Invalid choice. Valid menu options are 1-6. " << endl << endl;
				}
			}//switch menuChoice
		} while ( menuChoice != '6' ); //while

	return 0;
}
