//
// Created by Garrett on 4/18/18.
//

#ifndef WORKCONTACT_H
#define WORKCONTACT_H

#include "Contact.h"

class WorkContact : public Contact{
private:
	string company;
public:
	void setCompany(string);
	string getCompany() const;
};

#endif //GROUP_PROJECT_WORKCONTACT_H
