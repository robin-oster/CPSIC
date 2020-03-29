#pragma once
/* 
	statistics.h
	Declaration file for class Statistics.

*/

#ifndef STATISTICS_H
#define STATISTICS_H

#include "ksuPatient.h"
#include <vector>

/**

	@author Matthew Oster moster@kent.edu
*/

class Statistics {
public:

	/**
	Logs a new patient into the system's collection of registered patients.

	@param patient The patient to be logged into the collection.
	*/
	void logNewPatient(ksuPatient patient);

	/**
	Increments fluCount.
	*/
	void incrementFluCount() { fluCount++; }
	/**
	Increments coronaCount.
	*/
	ksuPatient incrementCoronaCount();
	/**
	Increments counselingCount.
	*/
	void incrementCounselingCount() { counselingCount++; }
	
	/**
	Calculates the percentages of patients who exhibit flu-like symptoms, the percentage who have contracted Coronavirus,
	and the percentage who have sought counseling for Coronavirus-related reasons.
	*/
	void calculatePercentages();

	/**
	Simple accessor methods.
	*/
	int getPatientCount() { return patientCount; }
	int getFluCount() { return fluCount; }
	int getCoronaCount() { return coronaCount; }
	int getCounselingCount() { return counselingCount; }
	double getFluPercent() { return fluPercent; }
	double getCoronaPercent() { return coronaPercent; }
	double getCounselingPercent() { return counselingPercent; }

private:
	/**
	Checks the patient's ID to see if they are already registered in the system. If so, return true. If not, return false.
	This is a helper function for logNewPatient.

	@param patient The patient who's ID is being looked for in the system.
	*/
	bool checkID(ksuPatient patient);

	/**
	Resposible for storing collection of registered patients.
	*/
	std::vector<ksuPatient> registeredPatients;

	int patientCount; /*!< Number of unique patients registered in the system. */
	int fluCount; /*!< Number of patients exhibiting flu-like symptoms. */
	int coronaCount; /*!< Number of patients who have contracted Coronavirus. */
	int counselingCount; /*!< Number of patients who have sought counseling for Coronavirus related reasons. */
	double fluPercent; /*!< Percentage of patients exhibiting flu-like symptoms. */
	double coronaPercent; /*!< Percentage of patients who've contracted Coronavirus.*/
	double counselingPercent; /*!< Percentage of patients who've sought counseling for Coronavirus-related reasons. */

};

#endif