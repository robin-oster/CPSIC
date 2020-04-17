
/**
    hsFaculty.cpp
    Declaration file for the class hsFaculty.
*/

#include "hsFaculty.h"
#include <iostream>
using namespace std;


hsFaculty::hsFaculty() {
	User();
}

hsFaculty::hsFaculty(const User& source) {
	setID(source.getID());
	setName(source.getName());
	setPassword(source.getPassword());
}

hsFaculty::hsFaculty(const hsFaculty& source) {
	setID(source.getID());
	setName(source.getName());
	setPassword(source.getPassword());
}

hsFaculty hsFaculty::operator=(const hsFaculty& source) {
	setID(source.getID());
	setName(source.getName());
	setPassword(source.getPassword());
	return *this;
}

bool hsFaculty::operator==(const hsFaculty& source) {
	if (getID() == source.getID() && getName() == source.getName() && getPassword() == source.getPassword())
		return true;
	else return false;
}

/*
void hsFaculty::viewSchedule(schedule)
{
    //displays schedule
}

void hsFaculty::editSchedule(schedule)
{
    //ask if user wants to add dates or remove dates & enters those functions
}

void hsFaculty::addDates(schedule)
{
    // adds new dates to semester schedule
}

void hsFaculty::removeDates(schedule)
{
    //removes dates from semester schedule
}

void hsFaculty::removeAvailableTimes(schedule)
{
    
}
*/
void hsFaculty::showStats(coronaInfo nationalStats, Statistics stats)
{
    User::showStats(nationalStats); // displays base class function first
    cout << "Patients Registered:\t\t" << stats.getPatientCount() << endl;
    cout << "  Flu like Symptoms:\t\t" << stats.getFluCount() << "  /  " << stats.getFluPercent() << endl;
    cout << "# of Patients with Coronavirus:\t\t" << stats.getCoronaCount() << "  /  " << stats.getCoronaPercent() << endl;
    cout << "# of Patients who saught Counseling:\t" << stats.getCounselingCount() << "  /  " << stats.getCounselingPercent() << endl;
}

/*
void updateRecord(User, Statistics)
{
    /* system will ask questions, as faculty answers them pertaining the patient,
     answers will be wrote to file & statistics will be updated also  */
    
    /// ifstream -> open patient record file with corresponding ID
    /*  if no matching record,
            create new record   */
    /// ofstream -> adds information to patient record
/*
}

void hsFaculty::viewRecord(User)
{
    // ifstream -> open patient record file with corresponding ID
    // only view file
}

*/