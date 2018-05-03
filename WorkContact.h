//
// Created by Garrett on 4/18/18.
//

#ifndef WORKCONTACT_H
#define WORKCONTACT_H

#include "Contact.h"

class WorkContact : public Contact{
<<<<<<< HEAD
private:
	string company;
public:
	void setCompany(string);
	string getCompany() const;
=======
public:
	WorkContact()
	{typeOfContact = 2;}
	int getTypeofContact() const;
private:
	int typeOfContact;
>>>>>>> branch 'master' of https://github.com/jermsn/CS2Project_ContactManager.git
};

#endif //GROUP_PROJECT_WORKCONTACT_H
