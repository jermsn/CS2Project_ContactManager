//
// Created by Garrett on 4/18/18.
//

#include "RelativeContact.h"

//****************************************************************
//	Mutator for relationshp
//****************************************************************
void RelativeContact::setRelationship(string r) {
	relationship = r;
}

//****************************************************************
//	Accessor for relationship
//****************************************************************
string RelativeContact::getRelationship() const {
	return relationship;
}
