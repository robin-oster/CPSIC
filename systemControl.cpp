/*
	systemAccess.cpp
	Declaration file for the class systemAccess.

*/

#include "systemControl.h"
#include "ksuPatient.h"
#include <algorithm>
#include <string>
#include <iostream>


// Still have to implement database and find a way to distinguish ksuPatient from hsFaculty
void systemControl::logOn() {
	int id;
	std::string password;


	// User enters info
	std::cout << "Please enter an ID and password.\nID: ";
	std::cin >> id;
	std::cout << "Password: ";
	std::cin >> password;

	User thisUser;
	thisUser.setID(id); thisUser.setPassword(password); // Set user info
	if (verifyUser(thisUser)) {	// If user has been found in the database
		if (thisUser.getID() != 00000001 && thisUser.getID() != 00000002 && thisUser.getID() != 00000003 &&
			thisUser.getID() != 00000004 && thisUser.getID() != 00000005) { // hsFaculty ID values
			patientUser = ksuPatient(thisUser);
			auto userIt = std::find(registeredPatients.begin(), registeredPatients.end(), patientUser);
			if (userIt == registeredPatients.end()) //patient not yet registered, register them
				registeredPatients.push_back(thisUser); 
			return;
		}
		else { // user is hsFaculty
			facultyUser = hsFaculty(thisUser);
			facultyAccess = true;
			return;
		};
	}
	else {
		std::cout << "Invalid ID or password.\n";
		logOn(); // Repeat sign-in process
	}
}

void systemControl::logOff(){
}

void systemControl::networkUpdate() {

}

bool systemControl::verifyUser(User thisUser){
	// find user in database
	return true;
}
