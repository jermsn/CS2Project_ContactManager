//
// Created by Garrett on 4/18/18.
//

#include "WorkContact.h"

// Destructor
WorkContact::~WorkContact() {}

void WorkContact::setCompany(string inCompany) {
	company = inCompany;
}

string WorkContact::getCompany() const {
	return company;
}

int WorkContact::getTypeOfContact() const {
	return typeOfContact;
}

