
/**
    hsFaculty.cpp
    Declaration file for the class hsFaculty.
*/

#include "hsFaculty.h"
#include "systemControl.h"
#include "cstdlib"
#include "string"
#include <sstream>
#include <fstream>
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

void updateRecord(schedule schedule, User faculty, Statistics *stats)
{
    User patient;
    systemControl sys;
    
    ofstream o_stream;
    stringstream s_stream;
    
    int id;
    string fileName, notes;
    bool checked = false;
    bool counselling, flu, tested_corona, positive_corona;
    
    cout << endl;

    do
    {
        cout << "\nEnter Patient ID: #";
        cin >> id;
        
        patient.setID(id);
        
        if (!sys.verifyUser(patient))
        {
            cout << "\nError: Patient not found.\n\n";
        }
        else
        {
            checked = true;
        
            s_stream << id;
            fileName = s_stream.str();
        
            o_stream.open(fileName, std::ios::app);
        
            if (!o_stream.is_open())
            {
                checked = false;
                cout << "\nError: Could not open file.\n\n";
            }
        }
    } while (!checked);
    
    // Printing Patient & Appointment details to Record
    o_stream << "==========================================================================\n\n";
    o_stream << "Patient Name: " << patient.getName();
    o_stream << "\t\t\t\tID: #" << patient.getID();
    o_stream << "\n\nPractitioner Seen: " << faculty.getName();
    o_stream << "\t\t\tApt: "; // << schedule.printAppt();
    
    cout << "\n----------------------------------\n\n";
    cout << "\tEnter: 1 for Yes, 0 for No.\n\n";
    cout << "----------------------------------\n\n";
    
    // Input Counselling
    cout << "Patient seen for counselling services: ";
    o_stream << "\n\nPatient seen for counselling services: ";
    cin >>  counselling;
    
        if (counselling)
        {
            o_stream << "YES";
            stats->incrementCounselingCount();
        }
        else
        {
            o_stream << "NO";
        }
    
    
    // Input Flu Like Symptoms
    cout << "\nPatient showed flu like symptoms: ";
    o_stream << "\n\nPatient showed flu like symptoms: ";
    cin >>  flu;
    
        if (flu)
        {
            o_stream << "YES";
            stats->incrementFluCount();
        }
        else
        {
            o_stream << "NO";
        }
    
    // Input Tested for Coronavirus
    cout << "\nPatient was tested for the Coronavirus: ";
    o_stream << "\nPatient was tested for the Coronavirus: ";
    cin >> tested_corona;
    
        if (tested_corona)
        {
            o_stream << "YES";
        }
        else
        {
            o_stream << "NO";
        }
    
    // Input TESTED POSITIVE for Coronavirus
    cout << "\nPatient TESTED POSITIVE for the Coronavirus: ";
    o_stream << "\nPatient TESTED POSITIVE for the Coronavirus: ";
    cin >> positive_corona;
    
        if (positive_corona)
        {
            o_stream << "YES";
            stats->incrementCoronaCount();
        }
        else
        {
            o_stream << "NO";
        }
    
    // Allow faculty to enter notes
    cout << "\nNotes: ";
    o_stream << "\n\nNotes:\n\n\t";
    cin.ignore();
    getline(cin,notes);
    o_stream << notes;
    o_stream << "\n\n==========================================================================\n";
    
    // Closing stream
    o_stream.close();
    
    if (!o_stream.is_open())
    {
        cout << "\nWriting Complete: Information written to record.";
    }
}

void hsFaculty::viewRecord()
{
    User patient;
    systemControl sys;
       
    ifstream i_stream;
    stringstream s_stream;
       
    int ID;
    string fileName;
    bool checked = false;
       
    cout << endl;

    do
    {
        cout << "\nEnter Patient ID to view: #";
        cin >> ID;
           
        patient.setID(ID);
           
        if (!sys.verifyUser(patient))
           {
               cout << "\nError: Patient not found.\n\n";
           }
        else
           {
               checked = true;
           
               s_stream << ID;
               fileName = s_stream.str();
           
               i_stream.open(fileName);
           
               if (!i_stream.is_open())
               {
                   checked = false;
                   cout << "\nError: Could not open file.\n\n";
               }
           }
        
       } while (!checked);
    
    cout << endl << i_stream.rdbuf();
    
    i_stream.close();
}

