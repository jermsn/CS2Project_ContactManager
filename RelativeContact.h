//
// Created by Garrett on 4/18/18.
//

#ifndef RELATIVECONTACT_H
#define RELATIVECONTACT_H

#include "Contact.h"

class RelativeContact : public Contact{
private:
	string relationship;
	int typeOfContact;
public:
	// Constructor
	RelativeContact()
<<<<<<< HEAD
	{this->setTypeOfContact(3);}
=======
	{typeOfContact = 3;}
>>>>>>> fc4444ce10276da7b4f91247975b684753ad26a2
	// Destructor
	~RelativeContact();
	void setRelationship(string);
	string getRelationship() const;
	int getTypeOfContact() const;
};

#endif //GROUP_PROJECT_RELATIVECONTACT_H
