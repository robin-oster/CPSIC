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
pair<User*, bool> systemControl::logOn() {
	int id;
	std::string password;


	// User enters info
	std::cout << "Please enter an ID and password.\nID: ";
	std::cin >> id;
	std::cout << "Password: ";
	std::cin >> password;

	static User thisUser;
	thisUser.setID(id); thisUser.setPassword(password); // Set user info
	if (verifyUser(thisUser)) {	// If user has been found in the database
		if (thisUser.getID() != 00000001 && thisUser.getID() != 00000002 && thisUser.getID() != 00000003 &&
			thisUser.getID() != 00000004 && thisUser.getID() != 00000005) { // hsFaculty ID values?
			ksuPatient patientUser(thisUser, true);
			
			auto userIt = std::find(registeredPatients.begin(), registeredPatients.end(), patientUser);
			if (userIt == registeredPatients.end()) { //patient not yet registered, register them
				registeredPatients.push_back(patientUser);

			}
			return std::make_pair(&thisUser, patientUser.getStudentStatus());
			
		}
		else { // user is hsFaculty
			facultyAccess = true;
			return std::make_pair(&thisUser, false);
		};
	}
	else {
		std::cout << "Invalid ID or password.\n";
		logOn(); // Repeat sign-in process
	}
}

bool systemControl::logOff(){
	char choice;
	cout << "Really log off? Y/N: ";
	cin >> choice;
	if (choice == 'y' || choice == 'Y') return true;
	else return false;
}

void systemControl::networkUpdate() {

}

void systemControl::visualizeStats() {
	char squareGraph[11][11];
	
	for (int i = 0; i < 11; i++) squareGraph[i][0] = '|';
	for (int i = 0; i < 11; i++) squareGraph[10][i] = '-';
	for (int i = 0; i < 10; i++)
		for (int j = 1; j < 11; j++) squareGraph[i][j] = '.';
	
	cout << "TEST\n";
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			cout << squareGraph[i][j];
		}
		cout << endl;
	}


	auto statStart = statSet.begin();
	auto coronaStart = nationalInfo.begin();
	// shows last 10 snapshots
	if (statSet.size() > 10) statStart = statSet.end() - 11;
	if (nationalInfo.size() > 10)  coronaStart = nationalInfo.end() - 11;


	cout << "\n\n";
	cout << "CORONAVIRUS CASES IN THE US\n";
	for (coronaStart; coronaStart != nationalInfo.end(); coronaStart++) {
		int i = 1;
		int j = 1;
		int graphStat = coronaStart->getUSCount() ;
		while (graphStat > 0 && j < 11) {
			graphStat /= 50;
			squareGraph[j][i] = 'x';
			j++;
		}
		i++;
	}

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			cout << squareGraph[i][j];
		}
		cout << endl;
	}
	
	for (int i = 0; i < 10; i++)
		for (int j = 1; j < 11; j++) squareGraph[i][j] = '.';

	cout << "\n\n";
	cout << "CORONAVIRUS CASES IN OHIO\n";
	for (coronaStart; coronaStart != nationalInfo.end(); coronaStart++) {
		int i = 1;
		int j = 10;
		int graphStat = coronaStart->getOhioCount();
		while (graphStat > 0 && j > 0) {
			graphStat -= 10;
			squareGraph[j][i] = 'x';
			j--;
		}
		i++;
	}

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			cout << squareGraph[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < 10; i++)
		for (int j = 1; j < 11; j++) squareGraph[i][j] = '.';

	cout << "\n\n";
	cout << "CORONAVIRUS CASES AT KSU\n";
	for (statStart; statStart != statSet.end(); statStart++) {
		int i = 1;
		int j = 1;
		int graphStat = statStart->getCoronaCount();
		while (graphStat > 0 && j < 11) {
			graphStat -= 5;
			squareGraph[j][i] = 'x';
			j++;
		}
		i++;
	}

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			cout << squareGraph[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < 10; i++)
		for (int j = 1; j < 11; j++) squareGraph[i][j] = '.';

	cout << "\n\n";
	cout << "TOTAL NUMBER OF KSU-HS CLIENTS\n";
	for (statStart; statStart != statSet.end(); statStart++) {
		int i = 1;
		int j = 1;
		int graphStat = statStart->getPatientCount();
		while (graphStat > 0 && j < 11) {
			graphStat -= 5;
			squareGraph[j][i] = 'x';
			j++;
		}
		i++;
	}

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			cout << squareGraph[i][j];
		}
		cout << endl;
	}

	char percentGraph[11][50];
	for (int i = 0; i < 11; i++) percentGraph[i][0] = '|';
	for (int i = 1; i < 11; i++)
		for (int j = 1; j < 50; j++) percentGraph[i][j] = '.';

	/*
	cout << "\n\n";
	cout << "PERCENTAGE OF KSU-HS CLIENTS EXHIBITING FLU-LIKE CONDITIONS\n";
	for (statStart; statStart != statSet.end(); statStart++) {
		statStart->calculatePercentages();
		int i = 1;
		int j = 1;
		if(statStart->getFluPercent() != 0) int j = statStart->getFluPercent() / 2;
		for(int k = 1; k < j; k++){
			percentGraph[i][k] = 'x';
		}
		i++;
	}

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 50; j++) {
			cout << percentGraph[i][j];
		}
		cout << endl;
	}

	for (int i = 1; i < 11; i++)
		for (int j = 1; j < 50; j++) squareGraph[i][j] = '.';

	cout << "\n\n";
	cout << "PERCENTAGE OF KSU-HS CLIENTS WITH CORONAVIRUS\n";
	for (statStart; statStart != statSet.end(); statStart++) {
		statStart->calculatePercentages();
		int i = 1;
		int j = 1;
		if (statStart->getCoronaPercent() != 0) int j = statStart->getCoronaPercent() / 2;
		for (int k = 1; k < j; k++) {
			percentGraph[i][k] = 'x';
		}
		i++;
	}

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 50; j++) {
			cout << percentGraph[i][j];
		}
		cout << endl;
	}

	for (int i = 1; i < 11; i++)
		for (int j = 1; j < 50; j++) squareGraph[i][j] = '.';

	cout << "\n\n";
	cout << "PERCENTAGE OF KSU-HS CLIENTS WHO'VE BEEN TO COUNSELING\n";
	for (statStart; statStart != statSet.end(); statStart++) {
		statStart->calculatePercentages();
		int i = 1;
		int j = 1;
		if (statStart->getCounselingPercent() != 0) int j = statStart->getCounselingPercent() / 2;
		for (int k = 1; k < j; k++) {
			percentGraph[i][k] = 'x';
		}
		i++;
	}

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 50; j++) {
			cout << percentGraph[i][j];
		}
		cout << endl;*/
	
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
