/*
	coronaInfo.cpp
	Declaration file for the class coronaInfo.
*/

#include "coronaInfo.h"
#include <vector>

int coronaInfo::updateOhioCount() {
	int previousCount = ohioCount;
	if (infectionRate <= 0) infectionRate += rand() % 6;
	else infectionRate += (rand() % 11) - 5;

	if (ohioCount + infectionRate <= 0) ohioCount = 0;
	else
	{
		ohioCount += infectionRate;
		usCount += infectionRate;
	}

	return ohioCount - previousCount;
}

int coronaInfo::updateUSCount() {
	int previousCount = usCount;
	if (infectionRate <= 0) infectionRate += rand() % 6;
	else infectionRate += (rand() % 11) - 5;

	if (usCount + infectionRate <= 0) usCount = 0;
	else
	{
		usCount += infectionRate * 50;
	}
	
	return usCount - previousCount;
}