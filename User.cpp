/**
	User.cpp
	Declaration file for the class User.
*/

#include "User.h"

User::User() {
	ID = 00000000;
	name = "";
	password = "";
}

User::User(User& source) {
	ID = source.getID();
	name = source.getName();
	password = source.getPassword();
}

User User::operator=(User& source) {
	ID = source.getID();
	name = source.getName();
	password = source.getPassword();
}

bool User::operator==(User target) {
	if (ID == target.ID && name == target.name && password == target.password)
		return true;
	else return false;
}