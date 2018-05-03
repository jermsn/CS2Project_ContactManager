//
// Created by Garrett on 4/18/18.
//

#include "RelativeContact.h"

void RelativeContact::setRelationship(string r) {
	relationship = r;
}

string RelativeContact::getRelationship() const {
	return relationship;
}

int RelativeContact::getTypeOfContact() const {
	return typeOfContact;
}