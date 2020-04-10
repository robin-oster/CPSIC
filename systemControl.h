#pragma once
/*
	systemAccess.h
	Declaration file for class systemAccess.

*/

#ifndef SYSTEM_CONTROL_H
#define SYSTEM_CONTROL_H

//#include "statistics.h"
#include "ksuPatient.h"
//#include "coronaInfo.h"
//#include "bill.h"
#include <string>
#include <vector>

/**

	@author Matthew Oster moster@kent.edu
*/

class systemControl {
public:
	
	/**
	Facilitates the process of logging a user in. Returns true if successful.

	@param id The user's 8 digit KSU ID.
	@param password The password to the account corresponding to the 8 digit ID.
	*/
	void logOn();

	/**
	Logs the current user out of the system.
	*/
	void logOff();
	
	/**
	Ensures that information is up to date across the system.
	*/
	void networkUpdate();

	/**
	Resposible for storing collection of registered patients.
	*/
	std::vector<ksuPatient> registeredPatients;

	/**
	Statistics object responsible for keeping track of KSU-HS patient information.
	*/
	//Statistics statSet;
	
	/**
	coronaInfo object responsible for keeping track of total US and Ohio cases.
	*/
	//coronaInfo nationalInfo;
	
	/**
	Bill object responsible for keeping track of payment information.
	*/
<<<<<<< HEAD
	//Bill bill;
=======
	Bill bill;
	
>>>>>>> 0d7fd5f2fce50c60c8adabda02f27d882055972c
private:
	/**
	Checks the user's info to find their corresponding database entry. Returns true if that user is in the database.

	@param thisUser The User who's info is being looked for in the database.
	*/
	bool verifyUser(User thisUser);
};

#endif
