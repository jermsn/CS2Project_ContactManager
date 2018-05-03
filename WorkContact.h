//
// Created by Garrett on 4/18/18.
//

#ifndef WORKCONTACT_H
#define WORKCONTACT_H

#include "Contact.h"

class WorkContact : public Contact{
<<<<<<< HEAD

public:
	WorkContact()
	{typeOfContact = 2;}
	int getTypeOfContact() const;
	void setCompany(string);
	string getCompany() const;
private:
	int typeOfContact;
	string company;
=======
public:
	WorkContact()
	{typeOfContact = 2;}
	int getTypeOfContact() const;
private:
	int typeOfContact;
>>>>>>> branch 'master' of https://github.com/jermsn/CS2Project_ContactManager.git
};

#endif //GROUP_PROJECT_WORKCONTACT_H
