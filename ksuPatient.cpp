
/**
    ksuPatient.cpp
    Declaration file for the class ksuPatient.
*/

#include "ksuPatient.h"
#include "schedule.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;


ksuPatient::ksuPatient(const ksuPatient& patient) {
	setID(patient.getID());
	setName(patient.getName());
	setPassword(patient.getPassword());
	student = patient.getStudentStatus();
	practitionerBill = patient.practitionerBill; //*(patient.getPractitionerBill());
	counselorBill = patient.counselorBill; //*(patient.getCounselorBill());
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

void ksuPatient::registerAppointment(schedule& schedule)
{
    //register appointment
    ifstream i_stream;
    stringstream s_stream;
    string month;
    string file_char;
    bool date_check = false;
    int day, year;
    
    int student_id = getID();
    string date, time;
    int doctor = 0;
    
    int facultyChoice;
    
    do {
    
        cout << "Enter the date you would like to schedule an appointment 'Apr xx 20xx': ";
        cin >> month >> day >> year;
       
        if (month == "Jan" || month == "Feb" || month == "Mar" || month == "Apr" || month == "May" || month == "Jun" || month == "Jul" || month == "Aug" || month == "Sept" || month == "Oct" || month == "Nov" || month == "Dec" )
        {
            if (day > 0 && day <= 31)
            {
                if (year > 2010 && year < 3000)
                {
                    date_check = true;
                } else { cout << "\nYEAR ERROR.\n"; }
            } else { cout << "\nDAY ERROR.\n"; }
        } else { cout << "\nMONTH ERROR.\n"; }
        
    } while (!date_check);
    
    s_stream << month << " " << day << " " << year;
    date = s_stream.str();
    
    cout << "Would You like to see a practioner or counselor?\n";
    cout << "Enter 1 for Practitioner, or 2 for Counselor: ";
    
    //will need to have a choice between individual faculty members rather than just the two types
    do
    {
        cin >> facultyChoice;
        if (facultyChoice != 1 && facultyChoice != 2)
        {
            cout << "Invalid input. Try again.\n";
        }
    } while (facultyChoice != 1 && facultyChoice != 2);

    if (facultyChoice == 1)
        {
            i_stream.open(date);
            
            if (!i_stream.is_open())
            {
                cout << "Error: No available appointment times on " << date;
            }
            else
            {
                char temp[25];
                
                cout << endl << "Displaying available appointment times for: " << date << endl;;
                
                while (getline(i_stream, file_char))
                {
                    if (file_char == "* 1 ")
                        cout << "\tDoc/Nurse 1:\t\t";
                    else if (file_char == "* 2 ")
                        cout << "\tDoc/Nurse 2:\t\t";
                    else if (file_char == "* 3 ")
                        cout << "\tDoc/Nurse 3:\t\t";
                    else if (file_char == "\n")
                        cout << endl << endl;
                    
                    else if (file_char == "* 4 ")
                        break;
                    
                    strcpy(temp, file_char.c_str());
                    
                    if (temp[0] == '-')
                    {
                        cout << "\t\t\t";
                    }
                    else if (temp[0] == '+')
                    {
                        cout << file_char.substr(2);
                        cout << "\t\t";
                    }
                    else if (temp[0] == '#')    { cout << endl; }
                }
   
                i_stream.close();
                
                cout << "\nWhich doctor would you like to see: ";
                cin >> doctor;
                cout << "\nEnter the time you would like to schedule your appointment in the format 'HH:MM': ";
                cin >> time;
            }
            
            schedule.saveAppt(student_id, date, time, doctor);
            
            addToPractitionerBill(schedule);
        }
    else if (facultyChoice == 2)
        {
            i_stream.open(date);
            bool found = false;
                     
            if (!i_stream.is_open())
            {
                cout << "Error: No available appointment times on " << date;
            }
            else
            {
                char temp[25];
                         
                cout << endl << "Displaying available appointment times for: " << date << endl;;
                         
                while (getline(i_stream, file_char))
                {
                    if (file_char == "* 4 ")
                    {
                        cout << "\tCounselor 1:\t\t";
                        found = true;
                    }
                    else if (file_char == "* 5 ")
                    {
                        cout << "\tCounselor 2:\t\t";
                        found = true;
                    }
                    else if (file_char == "\n")
                        cout << endl << endl;
                             
                    strcpy(temp, file_char.c_str());
                    
                    if (found)
                    {
                        if (temp[0] == '-')
                        {
                            cout << "\t\t\t";
                        }
                        else if (temp[0] == '+')
                        {
                            cout << file_char.substr(2);
                            cout << "\t\t";
                        }
                        else if (temp[0] == '#')    { cout << endl; }
                    }
                    
                }
            
                    i_stream.close();
                         
                    cout << "\nWhich doctor would you like to see: ";
                    cin >> doctor;
                    cout << "\nEnter the time you would like to schedule your appointment in the format 'HH:MM': ";
                    cin >> time;
            }
            
            if (doctor == 1)
            {
                doctor = 4;
            }
            else if (doctor == 2)
            {
                doctor = 5;
            }
            
            schedule.saveAppt(student_id, date, time, doctor);
            addToCounselorBill(schedule);
        }
}


void ksuPatient::viewAppointment(schedule schedule)
{
    schedule.printAppt();
}

/*
void ksuPatient::rescheduleAppointment(schedule)
{
    
}
*/
