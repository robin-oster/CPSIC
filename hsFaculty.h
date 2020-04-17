
#pragma once

/**
    hsFaculty.h
    Declaration file for class hsFaculty
*/

#ifndef HSFACULTY_H
#define HSFACULTY_H

#include "User.h"
#include "statistics.h"

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

    /**
     Displays the schedule.
     
     @param Schedule An instance of the current schedule
     */
    //void viewSchedule(schedule);
    
    /**
     Allows user to add additional dates to semester schedule or
     Allows user to remove dates from semester schedule or
     
     @param schedule An instance of the current schedule
     */
    //void editSchedule(schedule);
    
    /**
     Remove available times to semester schedule
     
     @param schedule An instance of the currant schedule
     */
    //void removeAvailableTimes(schedule);
    
    /**
     Displays current statistics of Coronavirus cases in Ohio & USA.
     Displays Coronavirus related statistics of HS Facility.
     
     @param nationalStats stats
     */
    void showStats(coronaInfo nationalStats, Statistics stats);
    
     /**
     Allows user to update patient record
     
     @param User User must be passed to find record.
     @param statistics
     */
    //void updateRecord(User, Statistics);
    
    /**
     Displays patient record.
     
     @param User User must be passed to find record.
     */
    //void viewRecord(User);

	

private:

    /**
     Adds additional dates to semester schedule
     
     @param Schedule An instance of the current schedule
     */
    //void addDates(schedule);
    
    /**
     removes dates from semester schedule
     
     @param Schedule An instance of the current schedule
     */
    //void removeDates(schedule);
   
};

#endif
