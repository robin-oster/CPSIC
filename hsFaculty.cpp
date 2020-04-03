
/**
    hsFaculty.cpp
    Declaration file for the class hsFaculty.
*/

#include "hsFaculty.h"
#include <iostream>
using namespace std;

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

void hsFaculty::showStats(statistics)
{
    User::showStats(statistics); // displays base class function first
    cout << "Patients Registered:\t\t" << statistics.getPatientCount() << endl;
    cout << "  Flu like Symptoms:\t\t" << statistics.getFluCount() << "  /  " << statistics.getFluPercent() << endl;
    cout << "# of Patients with Coronavirus:\t\t" << statistics.getCoronaCount() << "  /  " << statistics.getCoronaPercent() << endl;
    cout << "# of Patients who saught Counseling:\t" << statistics.getCounselingCount() << "  /  " << statistics.getCounselingPercent << endl;
}

