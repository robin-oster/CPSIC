#pragma once
/*
	systemAccess.h
	Declaration file for class systemAccess.

*/

#ifndef SYSTEM_CONTROL_H
#define SYSTEM_CONTROL_H

#include "statistics.h"
#include "ksuPatient.h"
#include "coronaInfo.h"
#include "bill.h"
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
	bool logOn(int id, std::string password);

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
	Statistics statSet;
	
	/**
	coronaInfo object responsible for keeping track of total US and Ohio cases.
	*/
	coronaInfo nationalInfo;
	
	/**
	Bill object responsible for keeping track of payment information.
	*/
	Bill bill;
	
private:
	/**
	Checks the patient's ID to see if they are already registered in the system. If so, return true. If not, return false.

	@param patient The patient who's ID is being looked for in the system.
	*/
	bool checkID(ksuPatient patient);
};

#endif
