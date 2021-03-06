//
// Created by Garrett on 4/18/18.
//

#ifndef CLIENTCONTACT_H
#define CLIENTCONTACT_H

#include "Contact.h"

class ClientContact : public Contact
{
public:
	// Constructor
	ClientContact()
	{
		clientSinceDate.setMonth(99, 99, 9999);
		clientSinceDate.setDay(99, 99, 9999);
		clientSinceDate.setYear(99, 99, 9999);
		this->setTypeOfContact(4);
	}
	// Destructor
	~ClientContact() {};
	// Accessors
	const string getClientSinceDate() const;// Return client since date
	// Mutators
	void setClientSinceDate(Date);				// Set birth date
private:
	Date clientSinceDate;// Date of initial contact with client
};

#endif //GROUP_PROJECT_CLIENTCONTACT_H
