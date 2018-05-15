//
// Created by Garrett on 4/22/18.
//

#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include "Contact.h"
#include "Functions.h"

using namespace std;

class ContactList {
private:
	struct ListNode{
		Contact *currentContact;	// Pointer to contact information
		struct ListNode *next;		// Pointer to the next node
	};

	ListNode *head;
	int count;
public:
	// Constructor
	ContactList();
	~ContactList();
	void appendNode(Contact *);
	void insertNode(Contact *);
	void deleteNode(Contact *);
	Contact* searchForContact(string firstN, string lastN);
	void displayList() const;
	bool empty();
	void writeContacts(fstream&) const;
	void readContacts(fstream&, ContactList& );
};

#endif
