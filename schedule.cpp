
//schedule.cpp

//Definition file for schedule class

//include necessary directories
#include "schedule.h"
#include "ksuPatient.h"
#include "hsFaculty.h"

//set namespace to std
using namespace std;

//constructor
schedule::schedule() {
	iSchedule.open ("schedule.txt");
	oSchedule.open ("schedule.txt");
	
	appointment appt;
}

schedule::schedule(const schedule& src) {
	iSchedule.open("schedule.txt");
	oSchedule.open("schedule.txt");

	appointment appt;
}

//printAppt function
//Displays appointment
void schedule::printAppt(appointment appt) {
	cout << appt.patient->getName() << " " << appt.faculty->getName() << " " << appt.date << " " << appt.timeslot << '\n';
}

//get and set functions
string schedule::getDate() {
	return appt.date;
}
string schedule::getTimeslot() {
	return appt.timeslot;
}
ksuPatient schedule::getPatient() {
	return appt.patient;
}
hsFaculty schedule::getStaff() {
	return *(appt.faculty);
}

void schedule::setDate(string date) {
	appt.date = date;
}
void schedule::setTimeslot(string timeslot) {
	appt.timeslot = timeslot;
}
void schedule::setPatient(ksuPatient patient) {
	appt.patient = &patient;
}
void schedule::setStaff(hsFaculty faculty) {
	appt.faculty = &faculty;
}

//saveAppt function
//saves appointment to schedule
void schedule::saveAppt(appointment appt) {
	if (oSchedule.is_open()) {
		oSchedule << appt.patient->getName() + ";" + appt.faculty->getName() + ";" << appt.date << ";" << appt.timeslot << "\n";
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
