
#pragma once

/**
    ksuPatient.h
    Declaration file for class ksuPatient.
 */

#ifndef KSUPATIENT_H
#define KSUPATIENT_H

#include "User.h"


/**
 
    @author Daniel Stephan dstepha3@kent.edu
 */

class ksuPatient: private User
{
public:
	
	ksuPatient();
	ksuPatient(const ksuPatient& patient);
	ksuPatient(User& user);

	ksuPatient operator=(const ksuPatient& patient);
	bool operator==(const ksuPatient& patient);

    /**
     Displays the user appointment.
     
     @param schedule An instance of the current schedule
     */
    //void viewAppointment(schedule);
    
    /**
     Assigns user to appointment in schedule
     
     @param schedule An instance of the current schedule
     */
    //void registerAppointment(schedule);
    
    /**
     Allows user to reschedule appointment in schedule
     
     @param schedule An instance of the current schedule
     */
    //void rescheduleAppointment(schedule);
    
private:

};

#endif
