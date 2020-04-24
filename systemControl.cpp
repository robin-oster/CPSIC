/*
	systemAccess.cpp
	Declaration file for the class systemAccess.

*/

#include "systemControl.h"
#include <algorithm>
#include <string>
#include <iostream>

/**
	@author Matthew Oster moster@kent.edu
*/

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
			thisUser.getID() != 00000004 && thisUser.getID() != 00000005) { // hsFaculty ID values?
			ksuPatient patientUser(thisUser, true);
			auto userIt = std::find(registeredPatients.begin(), registeredPatients.end(), patientUser);
			if (userIt == registeredPatients.end()) { //patient not yet registered, register them
				registeredPatients.push_back(patientUser);
			}
			return;
			
		}
		else { // user is hsFaculty
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

void systemControl::visualizeStats() {
	cout << "CORONAVIRUS CASES IN THE US\n";
	for (auto i = nationalInfo.begin(); i != nationalInfo.end(); i++) {
		for (auto j = 0; j <= i->getUSCount() / 50; j++) {
			cout << "x\n";
		}
		cout << " ";
	}
	
	cout << "\n\n";
	cout << "CORONAVIRUS CASES IN OHIO\n";
	for (auto i = nationalInfo.begin(); i != nationalInfo.end(); i++) {
		for (auto j = 0; j <= i->getOhioCount(); j++) {
			cout << "x\n";
		}
		cout << " ";
	}

	cout << "\n\n";
	cout << "CORONAVIRUS CASES AT KSU\n";
	for (auto i = statSet.begin(); i != statSet.end(); i++) {
		for (auto j = 0; j <= i->getCoronaCount(); j++) {
			cout << "x\n";
		}
		cout << " ";
	}

	cout << "\n\n";
	cout << "TOTAL NUMBER OF KSU-HS CLIENTS\n";
	for (auto i = statSet.begin(); i != statSet.end(); i++) {
		for (auto j = 0; j <= i->getPatientCount(); j++) {
			cout << "x\n";
		}
		cout << " ";
	}

	cout << "\n\n";
	cout << "PERCENTAGE OF KSU-HS CLIENTS EXHIBITING FLU-LIKE CONDITIONS\n";

	cout << "\n\n";
	cout << "PERCENTAGE OF KSU-HS CLIENTS WITH CORONAVIRUS\n";

	cout << "\n\n";
	cout << "PERCENTAGE OF KSU-HS CLIENTS WHO'VE BEEN TO COUNSELING\n";



}

void systemControl::calculateEarnings() {
	for (auto i = registeredPatients.begin(); i != registeredPatients.end(); i++) {
		practitionerEarnings += i->getPractitionerBill()->getPaidTotal();
		counselorEarnings += i->getCounselorBill()->getPaidTotal();
	}
	totalEarnings = practitionerEarnings + counselorEarnings;
}

bool systemControl::verifyUser(User thisUser) const{
	// find user in database
	return true;
}
