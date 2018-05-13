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
	~PersonalContact() {};
};

#endif //GROUP_PROJECT_PERSONALCONTACT_H
