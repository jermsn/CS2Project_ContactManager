//
// Created by Garrett on 4/22/18.
//

#include "ContactList.h"
#include "PersonalContact.h"
#include "RelativeContact.h"
#include "WorkContact.h"
#include "ClientContact.h"
#include "Functions.h"
#include <fstream>

using namespace std;


//*******************************************************
// editContact
//*******************************************************
//void ContactList::editContact(string firstN, string lastN){
//	Contact *cont1 = searchForContact(firstN, lastN);
//	if(!cont1) {
//		cout << "Contact Could not be found" << endl;
//		contactMenu();
//	}
//	else
//		contactEditMenu(reinterpret_cast< Contact& >(cont1));
//}

//*******************************************************
// appendNode for Contact List
//*******************************************************
void ContactList::appendNode(Contact *c1)
{
	ListNode *newNode;	// To point to a new node
	ListNode *nodePtr;	// To move through the list

	// Allocate a new node and store contact pointer there
	newNode = new ListNode;
	newNode->currentContact = c1;
	newNode->next = nullptr;

	// If there are no nodes in the list make newnode the first node
	if (!head)
		head = newNode;
	else // Otherwise, insert newNode at the end
	{
		// Initialize nodePtr to the head of the list
		nodePtr = head;

		// Find the last node in the list.
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		// Insert newNode as the last node.
		nodePtr->next = newNode;
	}
} // end appendNode

//*******************************************************
// insertNode for Contact List
//*******************************************************
void ContactList::insertNode(Contact *c1)
{
	ListNode *newNode;					// A new node
	ListNode *nodePtr;					// To traverse the list
	ListNode *previousNode = nullptr; 	// The previous node

	// Allocate a new node and store contact there
	newNode = new ListNode;
	newNode->currentContact = c1;

	// If there are not nodes in the list make newNode the first node
	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else // Otherwise, insert newNode
	{
		// Position nodePtr at the head of list
		nodePtr = head;

		// Initialize previousNode to nullptr
		previousNode = nullptr;

		// Skip all nodes with a contact type less than inserted contact
		while (nodePtr != nullptr && nodePtr->currentContact->getTypeOfContactInt() < c1->getTypeOfContactInt())
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If the new node is to be the 1st in the list, insert it before all other nodes
		if (previousNode == nullptr)
		{
			head = newNode;
			newNode = nullptr;
		}
		else // Otherwise insert after the previous node
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
} // end insertNode

//*******************************************************
// deleteNode for Contact List
//*******************************************************
void ContactList::deleteNode(Contact *c1)
{
	ListNode *nodePtr;		// To traverse the list
	ListNode *previousNode;	// To point to the previous node

	// If the list is empty, do nothing
	if (!head)
		return;

	// Determine if the first node is the one
	if (head->currentContact == c1)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose contact address is not equal to c1
		while (nodePtr != nullptr && nodePtr->currentContact != c1)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list, link the previous
		// node to the node after nodePtr, then delete nodePtr
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
} // End deleteNode

//*******************************************************
// displayList for ContactList
//*******************************************************
void ContactList::displayList() const
{
	ListNode *nodePtr; 	// To move through the list

	// Position nodePtr at the head of the list
	nodePtr = head;

	// While nodePtr points to a node, traverse the list
	while (nodePtr)
	{
		//Display the contact in this node
		displayContact(nodePtr->currentContact);

		//Move to the next node
		nodePtr = nodePtr->next;
	}
} // end displayList

//*******************************************************
// empty for ContactList
//*******************************************************
bool ContactList::empty()
{
	return ((!head) ? true : false);
} // end empty

//*******************************************************
// searchForContact for ContactList
//*******************************************************
Contact *ContactList::searchForContact(string firstN, string lastN){
	Contact *tempCont = nullptr;
	auto currentNode = head;
	string contName;

	if(!head)
		return nullptr;
	else if(!currentNode->next)
	{
		contName = currentNode->currentContact->getFirstName();
		if(compareNames(contName, firstN))
		{
			contName = currentNode->currentContact->getLastName();
			if (compareNames(contName, lastN))
			{
				tempCont = currentNode->currentContact;
				return tempCont;
			}
		}
	}
	else
		while(currentNode->next)
		{
			contName = currentNode->currentContact->getFirstName();
			if(compareNames(contName, firstN))
			{
				contName = currentNode->currentContact->getLastName();
				if (compareNames(contName, lastN))
				{
					tempCont = currentNode->currentContact;
					return tempCont;
				}
			}
			currentNode = currentNode->next;
		}
	return tempCont;
} // end searchForContact


//*******************************************************
// Constructor for Contact List
//*******************************************************
ContactList::ContactList()
{
	head = nullptr;
	count = 0; //initialize the counter to keep track of the number of contacts
}

//*******************************************************
// Destructor for Contact List
//*******************************************************
ContactList::~ContactList()
{
	ListNode *nodePtr;		// To traverse the list
	ListNode *nextNode;		// To point to the next node

	nodePtr = head;			// Position nodePtr at the head of the list

	while (nodePtr != nullptr)				// While nodePtr is not at the end of the list ...
	{
		nextNode = nodePtr->next;			// Save a pointer to the next node
		delete nodePtr;						// Delete the current node
		nodePtr = nextNode;					// Position nodePtr at the next node
	}
} // end destructor


//*******************************************************
// writeContacts for ContactList
//*******************************************************
void ContactList::writeContacts(fstream &outFile) const
{
	ListNode *nodePtr; 	// To move through the list

	// Position nodePtr at the head of the list
	nodePtr = head;

	// While nodePtr points to a node, traverse the list
	while (nodePtr)
	{
		//Display the contact in this node
		Contact outContact = *nodePtr->currentContact;
		cout << "Writing record for " << outContact.getFirstName() << " " << outContact.getLastName() << endl;

		// downcast pointer for Relative
//		RelativeContact *rContactPtr = dynamic_cast < RelativeContact * > (nodePtr->currentContact);
//		// downcast pointer for Work contact
//		WorkContact *wContactPtr = dynamic_cast < WorkContact * > (nodePtr->currentContact);
//		// downcast pointer for Client Contact
//		ClientContact *cContactPtr = dynamic_cast < ClientContact * > (nodePtr->currentContact);
//		// downcast pointer for Personal Contact
//		PersonalContact *pContactPtr = dynamic_cast < PersonalContact * > (nodePtr->currentContact);
//
//		if(rContactPtr != 0)
//		{
//			RelativeContact writeContact = *nodePtr->currentContact;
//			outFile.write( reinterpret_cast< const char * >( &writeContact ), sizeof( writeContact ) );
//		}
		outFile.write( reinterpret_cast< const char * >( &outContact ), sizeof( outContact ) );

		//Move to the next node
		nodePtr = nodePtr->next;
	}
} // end writeContact

//*******************************************************
// readContacts for ContactList
//*******************************************************
void ContactList::readContacts(fstream &inFile, ContactList &inList)
{
	while(!inFile.eof())
	{
		Contact inCont;
		inFile.read( reinterpret_cast<char *>(&inCont), sizeof(inCont));
		cout << "Read in record for " << inCont.getFirstName() << " " << inCont.getLastName() << endl;
 		//inList.appendNode(&inCont);
	}
} // end readContacts
