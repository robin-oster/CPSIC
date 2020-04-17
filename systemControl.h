#pragma once
/*
	systemAccess.h
	Declaration file for class systemAccess.

*/

#ifndef SYSTEM_CONTROL_H
#define SYSTEM_CONTROL_H

#include "statistics.h"
#include "User.h"
#include "ksuPatient.h"
#include "hsFaculty.h"
//#include "coronaInfo.h"
#include "bill.h"
#include <string>
#include <vector>

/**

	@author Matthew Oster moster@kent.edu
*/

class systemControl {
public:

	 
	void logOn(); /*!< Facilitates the process of logging a user in.*/
	void logOff(); /*!< Logs the current user out of the system.*/
	void networkUpdate(); /*!< Ensures that information is up to date across the system.*/
	void calculateEarnings(); /*!< Calculates total earnings in the practitioner department, counseling department, and both combined.*/

	/*!< Accessor Methods*/
	double getPractitionerEarnings() { return practitionerEarnings; }
	double getCounselorEarningss() { return counselorEarnings; }
	double getTotalEarnings() { return totalEarnings; }

	std::vector<ksuPatient> registeredPatients; /*!< Resposible for storing collection of registered patients.*/
	bool facultyAccess = false; /*!< Keeps track of whether user has faculty access (hsFaculty) or not (ksuPatient).*/
	Statistics statSet; /*!<Statistics object keeping track of statistical info*/
	coronaInfo nationalInfo; /*!<coronaInfo object responsible for keeping track of total US and Ohio cases.*/
	
private:
	/**
	Checks the user's info to find their corresponding database entry. Returns true if that user is in the database.

	@param thisUser The User who's info is being looked for in the database.
	*/
	bool verifyUser(User thisUser);
	
	double practitionerEarnings;
	double counselorEarnings;
	double totalEarnings;
};

#endif
