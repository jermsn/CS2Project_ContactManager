//
// Created by Garrett on 4/18/18.
//

#ifndef RELATIVECONTACT_H
#define RELATIVECONTACT_H

#include "Contact.h"

class RelativeContact : public Contact{
private:
	string relationship;
public:
	// Constructor
	RelativeContact()
<<<<<<< HEAD
	{this->setTypeOfContact(3);}
=======
	{typeOfContact = 3;}
	// Destructor
	~RelativeContact();
>>>>>>> ece71bcfd5534185f35d5f9a27bd2397f7a68b7a
	void setRelationship(string);
	string getRelationship() const;
};

#endif //GROUP_PROJECT_RELATIVECONTACT_H
