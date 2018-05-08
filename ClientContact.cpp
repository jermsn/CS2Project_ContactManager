//
// Created by Garrett on 4/18/18.
//

#include "ClientContact.h"

//****************************************************************
//	Accessor for Client Since Date
//****************************************************************
const string ClientContact::getClientSinceDate() const
{
	string tmpStr;

	if ( clientSinceDate.getYear() != 9999)
		tmpStr = to_string(clientSinceDate.getMonth()) + "/" + to_string(clientSinceDate.getDay()) + "/" + to_string(clientSinceDate.getYear());
	else
		tmpStr = "<Unknown>";

	return tmpStr;
}


//****************************************************************
//	Mutator for Client Since date
//****************************************************************
void ClientContact::setClientSinceDate(Date inputDate)
{
	clientSinceDate = inputDate;
}

int ClientContact::getTypeOfContact() const {
	return typeOfContact;
}
