/*
	statistics.cpp
	Declaration file for the class Statistics.
*/

#include "statistics.h"

Statistics::Statistics() {
	patientCount = 0;
	fluCount = 0;
	coronaCount = 0;
	counselingCount = 0;
	fluPercent = 0;
	coronaPercent = 0;
	counselingPercent = 0;
}

void Statistics::calculatePercentages() {
	fluPercent = double(fluCount) / patientCount * 100;
	coronaPercent = double(coronaCount) / patientCount * 100;
	counselingPercent = double(counselingCount) / patientCount * 100;
}
