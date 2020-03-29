#pragma once
/*
	systemAccess.h
	Declaration file for class systemAccess.

*/

#ifndef SYSTEM_ACCESS_H
#define SYSTEM_ACCESS_H

#include "statistics.h"
#include "ksuPatient.h"
#include "coronaInfo.h"
#include <string>
#include <vector>

/**

	@author Matthew Oster moster@kent.edu
*/

class systemAccess {
public:
	
	/**
	Facilitates the process of logging a user in. Returns true if successful.

	@param id The user's 8 digit KSU ID.
	@param password The password to the account corresponding to the 8 digit ID.
	*/
	bool logOn(int id, std::string password);

	/**
	Carries out the process of preparing, packaging, and sending an alert to the KSU website and Flash Alerts.
	*/
	void generateAlert();
	void networkUpdate();



	/**
	Statistics object responsible for keeping track of KSU-HS patient information.
	*/
	Statistics statSet;
	/**
	coronaInfo object responsible for keeping track of total US and Ohio cases.
	*/
	coronaInfo nationalInfo;


private:
	/**
	Helper function for generateAlert(). Responsible for publishing the details of the alert to the KSU website.
	*/
	void notifyKSU();
	
	/**
	Helper function for generateAlert(). Responsible for publishing the details of the alert to Flash Alerts.
	*/
	void notifyFlashAlerts();
	
	std::vector<ksuPatient> alertInfo; /*!< The collection of alert info to be published. */

};

#endif