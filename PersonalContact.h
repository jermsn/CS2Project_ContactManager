//
// Created by Garrett on 4/18/18.
//

#ifndef PERSONALCONTACT_H
#define PERSONALCONTACT_H

#include "Contact.h"

class PersonalContact : public Contact{
public:
	PersonalContact()
<<<<<<< HEAD
	{ this->setTypeOfContact(1);}
=======
	{typeOfContact = 1;}
	// Destructor
	~PersonalContact();
	int getTypeOfContact() const;
private:
	int typeOfContact;
>>>>>>> ece71bcfd5534185f35d5f9a27bd2397f7a68b7a
};

#endif //GROUP_PROJECT_PERSONALCONTACT_H
