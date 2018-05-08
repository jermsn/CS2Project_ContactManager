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
	{typeOfContact = 1;}
	int getTypeOfContact() const;
private:
	int typeOfContact;
};

#endif //GROUP_PROJECT_PERSONALCONTACT_H
