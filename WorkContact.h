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
	{this->setTypeOfContact(2);}
<<<<<<< HEAD
	// Destructor
	~WorkContact();
=======
=======
	{typeOfContact = 2;}
>>>>>>> fc4444ce10276da7b4f91247975b684753ad26a2
	int getTypeOfContact() const;
	void setCompany(string);
	string getCompany() const;
private:
	string company;
};

#endif //GROUP_PROJECT_WORKCONTACT_H
