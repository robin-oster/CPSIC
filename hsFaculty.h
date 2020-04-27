
#pragma once

/**
    hsFaculty.h
    Declaration file for class hsFaculty
*/

#ifndef HSFACULTY_H
#define HSFACULTY_H

#include "User.h"
#include "statistics.h"

class systemControl;

/**
    @author Daniel Stephan dstepha3@kent.edu
*/

class hsFaculty: private User
{
public:
	hsFaculty();
	hsFaculty(const User& source);
	hsFaculty(const hsFaculty& source);

	hsFaculty operator=(const hsFaculty& source);
	bool operator==(const hsFaculty& source);

	const string getName() const { return getUserName(); }

    /**
     Displays the schedule.
     
     @param Schedule An instance of the current schedule
     */
	void viewSchedule(schedule my_schedule);
    
    /**
     Allows user to add additional dates to semester schedule or
     Allows user to remove dates from semester schedule or
     
     @param schedule An instance of the current schedule
     */
    void editSchedule(schedule);
    
    
    /**
     Displays current statistics of Coronavirus cases in Ohio & USA.
     Displays Coronavirus related statistics of HS Facility.
     
     @param CoronaInfo nationalStats
     @param Statistics stats
     */
    void showStats(coronaInfo& nationalStats, Statistics& stats) const;
    
     /**
     Allows user to update patient record
     
     @param Statistics statSet
     @param systemControl sys
     */
    void updateRecord(Statistics& statSet, const systemControl& sys);
    
    /**
     Displays patient record.
     
     @param User User must be passed to find record.
     */
    void viewRecord(const systemControl &sys);

	

private:

    /**
     Adds additional dates to semester schedule
     
     @param Schedule An instance of the current schedule
     */
    void addDates(schedule& schedule);
    
    /**
     removes dates from semester schedule
     
     @param Schedule An instance of the current schedule
     */
    void removeDates(schedule& schedule);
   
};

#endif
