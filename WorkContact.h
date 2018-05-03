//
// Created by Garrett on 4/18/18.
//

#ifndef WORKCONTACT_H
#define WORKCONTACT_H

#include "Contact.h"

class WorkContact : public Contact{
public:
	WorkContact()
	{typeOfContact = 2;}
	int getTypeOfContact() const;
private:
	int typeOfContact;
};

#endif //GROUP_PROJECT_WORKCONTACT_H
