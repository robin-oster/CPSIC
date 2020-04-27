#pragma once
/*
	systemAccess.h
	Declaration file for class systemAccess.

*/

#ifndef SYSTEM_CONTROL_H
#define SYSTEM_CONTROL_H

#include "User.h"
#include "ksuPatient.h"
#include "hsFaculty.h"
#include "statistics.h"
#include "coronaInfo.h"
#include "bill.h"
#include <string>
#include <vector>
#include <utility>


/**

	@author Matthew Oster moster@kent.edu
*/

class systemControl {
public:
	bool logOn(User* thisUser); /*!< Facilitates the process of logging a user in.*/
	bool logOff(); /*!< Logs the current user out of the system.*/
	void networkUpdate(); /*!< Ensures that information is up to date across the system.*/
	void calculateEarnings(); /*!< Calculates total earnings in the practitioner department, counseling department, and both combined.*/
	void addStatisticSnapshot(const Statistics stat) { statSet.push_back(stat); }
	void addCoronaSnapshot(const coronaInfo c_info) { nationalInfo.push_back(c_info); }
	void visualizeStats();

	/*!< Accessor Methods*/
	double getPractitionerEarnings() { return practitionerEarnings; }
	double getCounselorEarnings() { return counselorEarnings; }
	double getTotalEarnings() { return totalEarnings; }
	int getPatientCount() { return registeredPatients.size(); }

	std::vector<ksuPatient> registeredPatients; /*!< Resposible for storing collection of registered patients.*/
	bool facultyAccess = false; /*!< Keeps track of whether user has faculty access (hsFaculty) or not (ksuPatient).*/
	std::vector<Statistics> statSet; /*!<Statistics object keeping track of statistical info*/
	std::vector<coronaInfo> nationalInfo; /*!<coronaInfo object responsible for keeping track of total US and Ohio cases.*/
	
	/**
	Checks the user's info to find their corresponding database entry. Returns true if that user is in the database.

	@param thisUser The User who's info is being looked for in the database.
	*/
	bool verifyUser(User thisUser) const;
	
private:
	double practitionerEarnings = 0;
	double counselorEarnings = 0;
	double totalEarnings = 0;
};

#endif
