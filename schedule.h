
//schedule.h

//Header File for schedule class

//Include necessary directories
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "ksuPatient.h"
#include "hsFaculty.h"

//set namespace to std
using namespace std;

//schedule class
class schedule {
	
	//Function Declarations
	public:
		
		//constructor
		schedule Schedule();
		
		//printAppt function
		//Displays appointment
		void printAppt(appointment appt);
		
		//get and set functions
		year_month_day getDate();
		time_of_day getTimeslot();
		ksuPatient getPatient();
		hsFacuty getStaff();
		
		void setDate(time_t);
		void setTimeslot(time_t timeslot);
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
		
		//apppointment structure
		//appointments saved to schedule
		struct appointment {
			//appointment data types
			year_month_day date;
			time_of day timeslot;
			ksuPatient patient;
			hsFaculty faculty
		};
};
