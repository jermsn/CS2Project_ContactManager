//
// Created by Garrett on 4/18/18.
//

#ifndef WORKCONTACT_H
#define WORKCONTACT_H

#include "Contact.h"

class WorkContact : public Contact{

public:
	// Constructor
	WorkContact()
	{typeOfContact = 2;}
	// Destructor
	~WorkContact();
	int getTypeOfContact() const;
	void setCompany(string);
	string getCompany() const;
private:
	int typeOfContact;
	string company;
};

#endif //GROUP_PROJECT_WORKCONTACT_H
