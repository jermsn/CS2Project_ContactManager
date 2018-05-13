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

	count = 0; //initialize the counter to keep track of the number of contacts
}

//*******************************************************
// Destructor for Contact List
//*******************************************************
ContactList::~ContactList(){
	while(head){
		auto currentNode = head; //temp ptr to traverse the list

		while(currentNode->nextContact){ //find the end
			currentNode = currentNode->nextContact;
		}
		delete currentNode; // delete the last node of the list
	}
}

//*******************************************************
// searchForContact
//*******************************************************
Contact *ContactList::searchForContact(string firstN, string lastN){
	Contact *tempCont;
	auto currentNode = head;

	while(currentNode->nextContact){
		if(currentNode->currentContact->getFirstName() == firstN) {
			if (currentNode->currentContact->getLastName() == lastN){
				tempCont = currentNode->currentContact;
				return tempCont;
			}
		}
		currentNode = currentNode->nextContact;
	}
}


//*******************************************************
// deleteContact
//*******************************************************
void ContactList::deleteContact(string firstN, string lastN){
	Contact *cont1 = searchForContact(firstN, lastN);
	cont1->resetContact();
}

//*******************************************************
// editContact
//*******************************************************
void ContactList::editContact(string firstN, string lastN){
	Contact *cont1 = searchForContact(firstN, lastN);
	contactEditMenu(reinterpret_cast< Contact& >(cont1));
}

//*******************************************************
// insert
//*******************************************************
void ContactList::insert(Contact *c1){
	if(count < 100)
		addContact(c1);
	else
		cout << "Your contact manager is full. Contact could not be added";
}

//*******************************************************
// addContact
//*******************************************************
void ContactList::addContact(Contact *c1){
	auto newNode = new listNode;
	newNode->currentContact = c1;

	if(!head)
		head = newNode;
	else {
		auto currentNode = head;

		while(currentNode){
			if(newNode->currentContact < currentNode->currentContact) {
				listNode* temp1, * temp2;
				temp1 = currentNode;
				temp2 = currentNode->nextContact;

				currentNode = newNode;
				currentNode->nextContact = temp1;
				currentNode->nextContact->nextContact = temp2;
			}
			else
				currentNode = currentNode->nextContact;
		}
	}
	count++;
}

//*******************************************************
// emptu
//*******************************************************
bool ContactList::empty(){
	return head->currentContact != nullptr ? true : false;
}

//*******************************************************
// printList
//*******************************************************
void ContactList::printList(){
	auto currentNode = head;

	while(currentNode){
		displayContact(currentNode->currentContact);
		currentNode = currentNode->nextContact;
	}
}
