//
// Created by Garrett on 4/22/18.
//

#include "ContactList.h"

//*******************************************************
// Constructor for Contact List
//*******************************************************
ContactList::ContactList(){
	auto newNode = new listNode; //create the first new node to put at the head of the list
	head = newNode; //fill the head
	auto currentNode = head; //temp ptr to traverse the list and not lose the place of the head

	//*******************************************************
	// Initialize the list with 100 empty contacts
	//*******************************************************
	for(size_t i = 0; i < 99; i++){
		auto newNode = new listNode;
		currentNode->nextContact = newNode;
		currentNode = currentNode->nextContact;
	}
}

//*******************************************************
// Destructor for Contact List
//*******************************************************
ContactList::~ContactList(){
	while(!head){
		auto currentNode = head; //temp ptr to traverse the list

		while(!currentNode->nextContact){ //find the end
			currentNode = currentNode->nextContact;
		}
		delete currentNode; // delete the last node of the list
	}
}

//*******************************************************
// searchForContact
//*******************************************************
Contact searchForContact(string firstN, string lastN){
	Contact tempCont;
	cout << "searching";
	return tempCont;
}

//*******************************************************
// deleteContact
//*******************************************************
void deleteContact(Contact cont1){
	cout << "contact deleted";
}