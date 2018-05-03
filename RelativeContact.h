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
	RelativeContact()
	{typeOfContact = 3;}
	void setRelationship(string);
	string getRelationship() const;
	int getTypeOfContact() const;
};

#endif //GROUP_PROJECT_RELATIVECONTACT_H
