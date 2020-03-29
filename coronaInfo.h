#pragma once
/*
	coronaInfo.h
	Declaration file for class Statistics.

*/

#ifndef CORONA_INFO_H
#define CORONA_INFO_H

/**

	@author Matthew Oster moster@kent.edu
*/

#include "ksuPatient.h"
#include <vector>

class coronaInfo {
public:
	/**
	Updates ohioCount based on national database data.
	*/
	std::vector<ksuPatient> updateOhioCount();
	/**
	Updates usCount based on national database data
	*/
	void updateUSCount();

	/**
	Returns ohioCount.
	*/
	int getOhioCount() { return ohioCount; }
	/**
	Returns usCount.
	*/
	int getUSCount() { return usCount; }
private:
	int ohioCount; /*!< Number of Coronavirus cases in Ohio. */
	int usCount; /*!< Number of Coronavirus casesin the US. */

};

#endif