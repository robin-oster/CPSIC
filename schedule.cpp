
//schedule.cpp

//Definition file for schedule class

//include necessary directories
#include "schedule.h"

//set namespace to std
using namespace std;

//constructor
schedule::Schedule() {
	iSchedule.open ("schedule.txt");
	oSchedule.open ("schedule.txt");
	
	appointment appt;
}

//printAppt function
//Displays appointment
void schedule::printAppt(appointment appt) {
	cout << appt.patient.getName() << " " << appt.faculty.getName() << " " << appt.date << " " << appt.timeslot << '\n';
}

//get and set functions
year_month_day schedule::getDate() {
	return appt.date;
}
time_of_day schedule::getTimeslot() {
	return appt.timeslot
}
ksuPatient schedule::getPatient() {
	return appt.patient.getName();
}
hsFaculty schedule::getStaff() {
	return appt.faculty.getName();
}

void schedule::setDate(year_month_day date) {
	appt.date = date;
}
void schedule::setTimeslot(time_of_day timeslot) {
	appt.date = timeslot;
}
void schedule::setPatient(ksuPatient patient) {
	appt.patient = patient.getName();
}
void schedule::setStaff(hsFaculty faculty) {
	appt.faculty = faculty.getName();
}

//saveAppt function
//saves appointment to schedule
void schedule::saveAppt(appointment appt) {
	if (oSchedule.is_open()) {
		oSchedule << appt.patient.getName() + ";" + appt.faculty.getName() + ";" + appt.date + ";" + appt.timeslot + "\n";
	}
}

//printSchedule Function
//Displays current schedule of appointments
void schedule::printSchedule() {
	string appt;
	if (iSchedule.is_open()) {
		while (getline(iSchedule, appt)) {
			cout << appt << '\n';
		}
	}
}
