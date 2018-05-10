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

		while(!currentNode->nextContact){ //find the end
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

	while(currentNode){
		if(currentNode->currentContact->getFirstName() == firstN) {
			if (currentNode->currentContact->getLastName() == lastN){
				tempCont = currentNode->currentContact;
				return tempCont;
			}
		}
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

void ContactList::bubbleSort(){
	Contact *tempCont1;
	Contact *tempCont2;
	auto currentNode = new listNode;
	currentNode = head;

	while(head){

	}
}