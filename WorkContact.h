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
<<<<<<< HEAD
	{this->setTypeOfContact(2);}
=======
	{typeOfContact = 2;}
	int getTypeOfContact() const;
	void setCompany(string);
	string getCompany() const;
private:
	int typeOfContact;
	string company;
>>>>>>> ece71bcfd5534185f35d5f9a27bd2397f7a68b7a
};

#endif //GROUP_PROJECT_WORKCONTACT_H
