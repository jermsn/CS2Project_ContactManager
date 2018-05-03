//
// Created by Garrett on 4/22/18.
//

#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include "Contact.h"
#include "Functions.h"

class ContactList {
private:
	struct listNode{
		Contact *currentContact = nullptr;
		listNode *nextContact = nullptr;
	};

	listNode *head;
public:
	ContactList();
	~ContactList();
	Contact *searchForContact(string, string);
	void deleteContact(string, string);
	void editContact(string, string);
};

#endif
