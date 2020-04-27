
#pragma once

/**
    ksuPatient.h
    Declaration file for class ksuPatient.
 */

#ifndef KSUPATIENT_H
#define KSUPATIENT_H

#include "User.h"
#include "schedule.h"
#include "bill.h"
#include <iostream>
#include <vector>

class schedule;

/**
 
    @author Daniel Stephan dstepha3@kent.edu
	@author Matthew Oster moster@kent.edu
 */

class ksuPatient: private User
{
public:
	
	ksuPatient() : User(), student(true) {}
	ksuPatient(bool isStudent) : User(), student(isStudent) {}
	ksuPatient(const ksuPatient& patient);
	ksuPatient(const User& user, bool isStudent);

	ksuPatient operator=(const ksuPatient& patient);
	bool operator==(const ksuPatient& patient);
	friend ostream& operator<<(ostream& os, const ksuPatient& patient);

	void addToPractitionerBill(const schedule& sched);
	void addToCounselorBill(const schedule& sched);
	void showPractitionerBill() { std::cout << "PRACTITIONER BILL\n"; practitionerBill.showBill(); }
	void showCounselorBill() { std::cout << "COUNSELOR BILL\n"; counselorBill.showBill(); }

    bool getStudentStatus() const { return student; }
	Bill* getPractitionerBill() { return &practitionerBill; }
	Bill* getCounselorBill() { return &counselorBill; }
	const string getName() const { return getUserName(); }

    /**
     Displays the user appointment.
     
     @param schedule An instance of the current schedule
     */
    void viewAppointment(schedule schedule);
    
    /**
     Assigns user to appointment in schedule

     */
    void registerAppointment(schedule& schedule);
    
    /**
     Allows user to reschedule appointment in schedule
     
     @param schedule An instance of the current schedule
     */
    //void rescheduleAppointment(schedule);

private:
	bool student;
	Bill practitionerBill;
	Bill counselorBill;
};

#endif
