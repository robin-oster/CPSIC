#pragma once

//schedule.h

//Header File for schedule class

#ifndef SCHEDULE_H
#define SCHEDULE_H

//Include necessary directories
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>

//set namespace to std
using namespace std;

/**
	@author Jakob Gojkov
	@author Matthew Oster moster@kent.edu
*/

class ksuPatient;
class hsFaculty;

//apppointment structure
//appointments saved to schedule
struct appointment {
	//appointment data types
	string date;
	string timeslot;
	ksuPatient* patient;
	hsFaculty* faculty;
};

//schedule class
class schedule {
	
	//Function Declarations
	public:
		
		//constructor
		schedule();
		schedule(const schedule& src);
		
		//printAppt function
		//Displays appointment
		void printAppt(appointment appt);
		
		//get and set functions
		string getDate();
		string getTimeslot();
		ksuPatient getPatient();
		hsFaculty getStaff();
		
		void setDate(string);
		void setTimeslot(string timeslot);
		void setPatient(ksuPatient patient);
		void setStaff(hsFaculty faculty);
		
		//saveAppt function
		//saves appointment to schedule
		void saveAppt(appointment appt);
		
		//printSchedule Function
		//Displays current schedule of appointments
		void printSchedule();
		
	private:
		//schedule file stream
		ifstream iSchedule;
		ofstream oSchedule;
		appointment appt;
};

#endif