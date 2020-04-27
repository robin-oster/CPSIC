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
bool systemControl::logOn(User* thisUser) {
	int id;
	std::string password;


	// User enters info
	std::cout << "Please enter an ID and password.\nID: ";
	std::cin >> id;
	std::cout << "Password: ";
	std::cin >> password;

	thisUser->setID(id); thisUser->setPassword(password); // Set user info
	if (verifyUser(*thisUser)) {	// If user has been found in the database
		if (thisUser->getID() != 00000001 && thisUser->getID() != 00000002 && thisUser->getID() != 00000003 &&
			thisUser->getID() != 00000004 && thisUser->getID() != 00000005) { // hsFaculty ID values?
			int studentStatus = rand() % 2;
			ksuPatient patientUser(*thisUser, studentStatus);
			
			auto userIt = std::find(registeredPatients.begin(), registeredPatients.end(), patientUser);
			if (userIt == registeredPatients.end()) { //patient not yet registered, register them
				registeredPatients.push_back(patientUser);

			}
			return patientUser.getStudentStatus();
			
		}
		else { // user is hsFaculty
			facultyAccess = true;
			return false;
		};
	}
	else {
		std::cout << "Invalid ID or password.\n";
		logOn(thisUser); // Repeat sign-in process
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
	for (int i = 0; i < 11; i++) squareGraph[10][i] = '_';
	for (int i = 0; i < 10; i++)
		for (int j = 1; j < 11; j++) squareGraph[i][j] = '.';
	squareGraph[10][0] = 'L';

	auto statStart = statSet.begin();
	auto coronaStart = nationalInfo.begin();
	// shows last 10 snapshots
	if (statSet.size() >= 10) statStart = statSet.end() - 10;
	if (nationalInfo.size() >= 10)  coronaStart = nationalInfo.end() - 10;


	cout << "\n\n";
	cout << "CORONAVIRUS CASES IN THE US\n";
	for (auto coronaIt = coronaStart; coronaIt != nationalInfo.end(); coronaIt++) cout << coronaIt->getUSCount() << "\t";
	cout << endl;
	
	int i = 9;
	int j = 1;
	for (auto coronaIt = coronaStart; coronaIt != nationalInfo.end(); coronaIt++) {
		int graphStat = coronaIt->getUSCount();
		i = 9;
		while (graphStat > 0 && i >= 0) {
			graphStat -= 500;
			squareGraph[i][j] = 'x';
			i--;
		}
		j++;
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
	for (auto coronaIt = coronaStart; coronaIt != nationalInfo.end(); coronaIt++) cout << coronaIt->getOhioCount() << "\t";
	cout << endl;

	j = 1;
	for (auto coronaIt = coronaStart; coronaIt != nationalInfo.end(); coronaIt++) {
		i = 9;
		int graphStat = coronaIt->getOhioCount();
		while (graphStat > 0 && i >= 0) {
			graphStat -= 10;
			squareGraph[i][j] = 'x';
			i--;
		}
		j++;
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
	for (auto statIt = statStart; statIt != statSet.end(); statIt++) cout << statIt->getCoronaCount() << "\t";
	cout << endl;

	j = 1;
	for (auto statIt = statStart; statIt != statSet.end(); statIt++) {
		i = 9;
		int graphStat = statIt->getCoronaCount();
		while (graphStat > 0 && i >= 0) {
			graphStat -= 5;
			squareGraph[i][j] = 'x';
			i--;
		}
		j++;
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
	for (auto statIt = statStart; statIt != statSet.end(); statIt++) cout << statIt->getPatientCount() << "\t";
	cout << endl;

	j = 1;
	for (auto statIt = statStart; statIt != statSet.end(); statIt++) {
		i = 9;
		int graphStat = statIt->getPatientCount();
		while (graphStat > 0 && i >= 0) {
			graphStat -= 3;
			squareGraph[i][j] = 'x';
			i--;
		}
		j++;
	}

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			cout << squareGraph[i][j];
		}
		cout << endl;
	}

	int graphStat = 0;
	char percentGraph[11][52];
	for (int i = 0; i < 11; i++) percentGraph[i][0] = '|';
	for (int i = 0; i < 11; i++) percentGraph[i][51] = '|';
	for (int i = 0; i < 11; i++)
		for (int j = 1; j < 51; j++) percentGraph[i][j] = '.';

	i = 0;
	cout << "\n\n";
	cout << "PERCENTAGE OF KSU-HS CLIENTS EXHIBITING FLU-LIKE CONDITIONS\n";
	for (auto statIt = statStart; statIt != statSet.end(); statIt++) {
		graphStat = statIt->getFluPercent();
		j = 1;
		while(graphStat > 0 && j < 51) {
			graphStat -= 2;
			percentGraph[i][j] = 'x';
			j++;
		}
		i++;
	}

	for (int i = 0; i < 11; i++) {
		cout << "0%\t";
		for (int j = 0; j < 52; j++) {
			cout << percentGraph[i][j];
		}
		cout << "\t100%\t";
		cout << endl;
	}


	for (int i = 1; i < 11; i++)
		for (int j = 1; j < 51; j++) percentGraph[i][j] = '.';

	i = 0;
	cout << "\n\n";
	cout << "PERCENTAGE OF KSU-HS CLIENTS WITH CORONAVIRUS\n";
	for (auto statIt = statStart; statIt != statSet.end(); statIt++) {
		graphStat = statIt->getCoronaPercent();
		j = 1;
		while (graphStat > 0 && j < 51) {
			graphStat -= 2;
			percentGraph[i][j] = 'x';
			j++;
		}
		i++;
	}

	for (int i = 0; i < 11; i++) {
		cout << "0%\t";
		for (int j = 0; j < 52; j++) {
			cout << percentGraph[i][j];
		}
		cout << "\t100%\t";
		cout << endl;
	}

	for (int i = 1; i < 11; i++)
		for (int j = 1; j < 50; j++) percentGraph[i][j] = '.';

	i = 0;
	cout << "\n\n";
	cout << "PERCENTAGE OF KSU-HS CLIENTS WHO'VE BEEN TO COUNSELING\n";
	for (auto statIt = statStart; statIt != statSet.end(); statIt++) {
		graphStat = statIt->getCounselingPercent();
		j = 1;
		while (graphStat > 0 && j < 51) {
			graphStat -= 2;
			percentGraph[i][j] = 'x';
			j++;
		}
		i++;
	}

	for (int i = 0; i < 11; i++) {
		cout << "0%\t";
		for (int j = 0; j < 52; j++) {
			cout << percentGraph[i][j];
		}
		cout << "\t100%\t";
		cout << endl;
	}
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
