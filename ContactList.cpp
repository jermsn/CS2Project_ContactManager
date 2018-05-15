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
		currentNode->nextContact = new listNode;
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
	Contact *tempCont = nullptr;
	auto currentNode = head;
	string contName;

	if(this->empty())
		return nullptr;
	else if(!currentNode->nextContact)
		contName = currentNode->currentContact->getFirstName();
		if(compareNames(contName, firstN)){
			contName = currentNode->currentContact->getLastName();
		if (compareNames(contName, lastN)){
			tempCont = currentNode->currentContact;
			return tempCont;
		}
	}
	else
		while(currentNode->nextContact){
			contName = currentNode->currentContact->getFirstName();
			if(compareNames(contName, firstN)){
				contName = currentNode->currentContact->getLastName();
				if (compareNames(contName, lastN)){
					tempCont = currentNode->currentContact;
					return tempCont;
				}
			}
			currentNode = currentNode->nextContact;
		}
	return tempCont;
}


//*******************************************************
// deleteContact
//*******************************************************
void ContactList::deleteContact(string firstN, string lastN){
	Contact *cont1 = searchForContact(firstN, lastN);
	if(!cont1){
		cout << "Contact Could not be found" << endl;
		contactMenu();
	}
	else{
		cout << "Contact Deleted: " << firstN << ", " << lastN << endl;
		cont1 = nullptr;
	}
	count--;
}

//*******************************************************
// editContact
//*******************************************************
void ContactList::editContact(string firstN, string lastN){
	Contact *cont1 = searchForContact(firstN, lastN);
	if(!cont1) {
		cout << "Contact Could not be found" << endl;
		contactMenu();
	}
	else
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

	if(!head->currentContact){
		head->currentContact = c1;
	}
	else{
		auto currentNode = head;
//		while(currentNode->nextContact->currentContact)
//			currentNode = currentNode->nextContact;
//		currentNode->currentContact = c1;

		while(currentNode->currentContact){
			if(c1 < currentNode->currentContact) {
				Contact *temp1, *temp2;
				temp1 = currentNode->currentContact;
				temp2 = currentNode->nextContact->currentContact;

				currentNode->currentContact = c1;
				currentNode->nextContact->currentContact = temp1;
				currentNode->nextContact->nextContact->currentContact = temp2;
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
	return (!head->currentContact ? true : false);
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
