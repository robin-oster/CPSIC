/**
	User.cpp
	Declaration file for the class User.
*/

#include "User.h"

bool User::operator==(User target) {
	if (ID == target.ID && password == target.password)
		return true;
	else return false;
}