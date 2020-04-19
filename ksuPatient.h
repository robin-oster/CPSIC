
#pragma once

/**
    ksuPatient.h
    Declaration file for class ksuPatient.
 */

#ifndef KSUPATIENT_H
#define KSUPATIENT_H

#include "User.h"
#include "bill.h"
#include <iostream>
#include <vector>

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

	bool getStudentStatus() const { return student; }
	const Bill* getPractitionerBill() const { return &practitionerBill; }
	const Bill* getCounselorBill() const { return &counselorBill; }
	const string getName() const { return getName(); }

	void addToPractitionerBill(const schedule &sched);
	void addToCounselorBill(const schedule &sched);
	void showPractitionerBill() { std::cout << "PRACTITIONER BILL\n"; practitionerBill.showBill(); }
	void showCounselorBill() { std::cout << "COUNSELOR BILL\n"; counselorBill.showBill(); }

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
	bool student;
	Bill practitionerBill;
	Bill counselorBill;
};

#endif
