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

#include <vector>
#include <random>

class coronaInfo {
public:
	coronaInfo() : ohioCount(0), usCount(0), infectionRate(0) {}
	/**
	Updates ohioCount based on national database data.
	*/
	int updateOhioCount();
	/**
	Updates usCount based on national database data
	*/
	int updateUSCount();

	void incrementOhioCount() { ohioCount++; }
	void incrementUSCount() { usCount++; }

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
	int infectionRate;

};

#endif