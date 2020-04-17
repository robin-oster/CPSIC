#pragma once
//schedule.h

//Header File for schedule class

//Include necessary directories
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "ksuPatient.h"

//set namespace to std
using namespace std;


//schedule class
class schedule {

	//Function Declarations
public:

	//constructor
	schedule();

	//printAppt function
	//Displays appointment
	void printAppt();

	//get and set functions
	string getDate();
	string getTimeslot();
	ksuPatient getPatient();
	//getStaff();

	void setDate();
	void setTimeslot(string timeslot);
	void setPatient(ksuPatient patient);
	//void setStaff();

	//saveAppt function
	//saves appointment to schedule
	void saveAppt(struct appointment appt);

	//printSchedule Function
	//Displays current schedule of appointments
	void printSchedule();

private:
	//schedule file stream
	ifstream iSchedule;
	ofstream oSchedule;

	//apppointment structure
	//appointments saved to schedule
	struct appointment {
		//appointment data types
		time_t Date;
		string Timeslot;
		ksuPatient patient;
		//health staff
	};
};