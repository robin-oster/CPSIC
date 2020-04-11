
/**
    ksuPatient.cpp
    Declaration file for the class ksuPatient.
*/

#include "ksuPatient.h"
#include <iostream>
using namespace std;

ksuPatient::ksuPatient() {
	User();
}

ksuPatient::ksuPatient(const ksuPatient& patient) {
	User();
	setID(patient.getID());
	setName(patient.getName());
	setPassword(patient.getPassword());
}

ksuPatient::ksuPatient(User &user) {
	User();
	setID(user.getID());
	setName(user.getName());
	setPassword(user.getPassword());
}

ksuPatient ksuPatient::operator=(const ksuPatient& patient)
{
	User();
	setID(patient.getID());
	setName(patient.getName());
	setPassword(patient.getPassword());
}

bool ksuPatient::operator==(const ksuPatient& patient) {
	if (getID() == patient.getID() && getName() == patient.getName() && getPassword() == patient.getPassword())
		return true;
	else return false;
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