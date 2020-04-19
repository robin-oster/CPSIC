
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
	for (auto i = patient.getBillList()->begin(); i != patient.getBillList()->end(); i++)
		billList.push_back(*i);
}

ksuPatient::ksuPatient(const User& user, bool isStudent) {
	setID(user.getID());
	setName(user.getName());
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
	return os;
}

void ksuPatient::addToPractitionerBill() {
	if (practitionerBill.getAmount() == 0) {
		if (student == true) practitionerBill.setBill(10, "today");
		else practitionerBill.setBill(30, "today");
	}
	else {
		if (student == true) practitionerBill.addToBill(10);
		else practitionerBill.addToBill(30);
	}
}

void ksuPatient::addToCounselorBill() {
	if (counselorBill.getAmount() == 0) {
		if (student == true) counselorBill.setBill(10, "today");
		else counselorBill.setBill(30, "today");
	}
	else {
		if (student == true) counselorBill.addToBill(10);
		else counselorBill.addToBill(30);
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