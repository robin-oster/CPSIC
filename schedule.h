#pragma once

/**
    schedule.h
    Declaration file for class schedule
*/

#ifndef SCHEDULE_H
#define SCHEDULE_H

//Include necessary directories
#include <fstream>
#include <string>
#include <ctime>

//set namespace to std
using namespace std;

/**
	@author Jakob Gojkov
	@author Matthew Oster moster@kent.edu
  @author Daniel Stephan dstepha3@kent.edu
*/

class ksuPatient;
class hsFaculty;

/**
    apppointment structure
    appointments saved to schedule
 */
struct appointment {
	//appointment data types
    bool isAvailable();
	string date;
	string timeslot;
	int patient = 0;
	int faculty;
};

class schedule {
	
	//Function Declarations
	public:
		schedule();
		schedule(const schedule& src);
		
        /**
            Displays appointment information.
         */

	  void printAppt();		
        /**
        Simple accessor methods.
        */
		string getDate();
		string getTimeslot();
		int getPatient();
		int getStaff();
		
        /**
         Simple set methods.
         */
		void setDate(string);
		void setTimeslot(string timeslot);
		void setPatient(int patient_id);
		void setStaff(int faculty_id);
		
        /**
        Saves appointment to the schedule
         
        @param string student_name
        @param string date
        @param string time
        @param int ID
        */
		void saveAppt(int student_id, string date, string time, int ID);
		
        /**
        Displays the schedule
         
        @param int integer containing userID must be passed
        */
		void printSchedule(int user_id);
    
        /**
         Adds Faculty available times to the schedule
     
         @param string string containing the date
         @param int integer containing userID
         @param string name of faculty member
         */
        void addTimes(string date, int user_id, string names);
    

	private:
        ofstream oSchedule;
        ifstream iSchedule;

    		appointment appointment;

    
        const string apt_times [12] = { "10:00", "10:30", "11:00", "11:30", "12:00", "12:30",
                            "01:00", "01:30", "02:00", "02:30", "03:00", "03:30" };
    
        void printPersonalSchedule(int user_id);
        void printPersonalSchedule(int user_id,string date);
    
        void printMasterSchedule();
        void printMasterSchedule(string date);
};

#endif
