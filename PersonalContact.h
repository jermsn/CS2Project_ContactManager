//
// Created by Garrett on 4/18/18.
//

#ifndef PERSONALCONTACT_H
#define PERSONALCONTACT_H

#include "Contact.h"

using namespace std;

class PersonalContact : public Contact{
public:
	PersonalContact()
	{ this->setTypeOfContact(1);}
<<<<<<< HEAD
	// Destructor
	~PersonalContact();
=======
=======
	{typeOfContact = 1;}
>>>>>>> fc4444ce10276da7b4f91247975b684753ad26a2
	int getTypeOfContact() const;
};

#endif //GROUP_PROJECT_PERSONALCONTACT_H
