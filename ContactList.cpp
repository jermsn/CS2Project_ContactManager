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
// 2018-05-14 Jnorvell edit - program was crashing because of this on exit
// unable to find cause - just implemented list as shown on C++HtP p1147
//*******************************************************
//ContactList::~ContactList(){
//	while(head){
//		auto currentNode = head; //temp ptr to traverse the list
//
//		while(currentNode->nextContact){ //find the end
//			currentNode = currentNode->nextContact;
//		}
//		delete currentNode; // delete the last node of the list
//
//	}
//}

ContactList::~ContactList()
{
	listNode *nodePtr;		// To traverse the list
	listNode *nextNode;		// To point to the next node

	nodePtr = head;			// Position nodePtr at the head of the list

	while (nodePtr != nullptr)				// While nodePtr is not at the end of the list ...
	{
		nextNode = nodePtr->nextContact;	// Save a pointer to the next node
		delete nodePtr;						// Delete the current node
		nodePtr = nextNode;					// Position nodePtr at the next node
	}
} // end destructor


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
	auto newNode = new listNode;	// To point to a new node
	newNode->currentContact = c1;	// give the address of the new contact

	if(!head->currentContact)		// If there are no nodes make newNode the first
		head = newNode;
	else {
		auto currentNode = head;	// To traverse the list

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
// empty
//*******************************************************
bool ContactList::empty(){
	return ((head->currentContact == nullptr) ? true : false);
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
