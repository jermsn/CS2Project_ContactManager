/*
 * Functions.h
 *
 *  Created on: Apr 15, 2018
 *      Author: jerem
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>

void clearCIN(void);
void contactMenu(void);
Contact* contactEntry();
void displayContact(Contact*);
void addBirthDate(Contact&);
void addAddress(Contact&);
void addContactPhones(Contact&);
void addContactEmail(Contact&);
void contactEditMenu(Contact&);
bool compareNames(string, string);

#endif /* FUNCTIONS_H_ */
