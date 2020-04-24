
/**
    ksuPatient.cpp
    Declaration file for the class ksuPatient.
*/

#include "ksuPatient.h"
#include <iostream>
#include <string>
using namespace std;


ksuPatient::ksuPatient(const ksuPatient& patient) {
	setID(patient.getID());
	setName(patient.getName());
	setPassword(patient.getPassword());
	student = patient.getStudentStatus();
	practitionerBill = *(patient.getPractitionerBill());
	counselorBill = *(patient.getCounselorBill());
}

ksuPatient::ksuPatient(const User& user, bool isStudent) {
	setID(user.getID());
	setName(user.getUserName());
	setPassword(user.getPassword());
	student = isStudent;
}

ksuPatient ksuPatient::operator=(const ksuPatient& patient)
{
	setID(patient.getID());
	setName(patient.getName());
	setPassword(patient.getPassword());
	return *this;
}

bool ksuPatient::operator==(const ksuPatient& patient) {
	if (getID() == patient.getID() && getName() == patient.getName() && getPassword() == patient.getPassword())
		return true;
	else return false;
}

ostream& operator<<(ostream& os, const ksuPatient& patient) {
	os << "ID: " << patient.getID() << endl;
	os << "Name: " << patient.getName() << endl;
	if (patient.getStudentStatus() == true) os << "Student\n";
	else os << "Not student\n";
	return os;
}

void ksuPatient::addToPractitionerBill(const schedule &sched) {
	if (practitionerBill.getAmount() == 0) {
		if (student == true) practitionerBill.setBill(10, sched);
		else practitionerBill.setBill(30, sched);
	}
	else {
		if (student == true) practitionerBill.addToBill(10, sched);
		else practitionerBill.addToBill(30, sched);
	}
}

void ksuPatient::addToCounselorBill(const schedule &sched) {
	if (counselorBill.getAmount() == 0) {
		if (student == true) counselorBill.setBill(10, sched);
		else counselorBill.setBill(30, sched);
	}
	else {
		if (student == true) counselorBill.addToBill(10, sched);
		else counselorBill.addToBill(30, sched);
	}
}

/*
void ksuPatient::viewAppointment(schedule)
{
    
}

void ksuPatient::registerAppointment(schedule)
{
    
}

void ksuPatient::rescheduleAppointment(schedule)
{
    
}
*/