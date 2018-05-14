//
// Created by Garrett on 4/18/18.
//
#include "WorkContact.h"

//****************************************************************
//	Mutator for company
//****************************************************************
void WorkContact::setCompany(string inCompany) {
	company = inCompany;
}

//****************************************************************
//	Accessor for company
//****************************************************************
string WorkContact::getCompany() const {
	return company;
}
