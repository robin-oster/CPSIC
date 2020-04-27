
//schedule.cpp

//Definition file for schedule class

//include necessary directories
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <iomanip>
#include "schedule.h"
#include "ksuPatient.h"
#include "hsFaculty.h"

//set namespace to std
using namespace std;

//constructor
schedule::schedule() {
    string current_date;
    stringstream s_stream;
    s_stream << __DATE__;
    current_date = s_stream.str();
    
    appointment appt;
}

schedule::schedule(const schedule& src) {
    string current_date;
    stringstream s_stream;
    s_stream << __DATE__;
    current_date = s_stream.str();
    
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
		//oSchedule << appt.patient->getName() + ";" + appt.faculty->getName() + ";" << appt.date << ";" << appt.timeslot << "\n";
	}
}

//printSchedule Function
//Displays current schedule of appointments
void schedule::printSchedule(int user_id)
{
    stringstream s_stream;
    int choice;
    string month;
    string date;
    int day, year;
    bool date_check = false;
    
    cout << "\nWhat schedule would you like to view?\n";
    cout << "Enter 1 for YOUR schedule TODAY.\n";
    cout << "Enter 2 for the MASTER schedule TODAY.\n";
    cout << "Enter 3 for a specfic date.\nInput: ";
    cin >> choice;
    
    switch (choice) {
        case 1:
            printPersonalSchedule(user_id);
            break;
        case 2:
            printMasterSchedule();
            break;
        case 3:
            
            do {
                cout << "Enter the date you would like to view in the format 'Apr xx 20xx': ";
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
            
            cout << "\nEnter 1 for your personal schedule.";
            cout << "\nEnter 2 for the master schedule.\nInput: ";
            cin >> choice;
            
            if (choice == 1)
            {
                printPersonalSchedule(user_id, date);
            }
            else if (choice == 2)
            {
                printMasterSchedule(date);
            }
            break;
        default:
            cout << "ERROR: Invalid Input\nInput: ";
    };

}

void schedule::addTimes(string date, int user_id, string name)
{
    ofstream edit;
    bool isAvailable;
    
    edit.open(date, std::ios::app);
    
    if (!edit.is_open())
    {
        cout << "Error: Could not open file.";
        return;
    }
    
    edit << "\n* " << user_id << " " << name;
    
    cout << "\nEnter 1 for Yes or 0 for No, if you are available at the following times:\n";
    
    for (int i = 0; i < 12; i++)
    {
        cout << apt_times[i] << " - ";
        cin >> isAvailable;
        
        if (isAvailable)
        {
            edit << "\n+ " << apt_times[i];
        }
        else
        {
            edit << "\n- " << apt_times[i] << " : OFF.";
        }
    }
    
    edit << "\n#\n";
    
    edit.close();
    
    if (!edit.is_open())
        { cout << "\nInformation Saved.\n"; }
}

void schedule::printPersonalSchedule(int user_id)
{
    int temp = user_id;
    string date = __DATE__;
    
    printPersonalSchedule(temp, date);
}

void schedule::printPersonalSchedule(int user_id, string date)
{
    stringstream s_stream;
    string target;
    bool found = false;
    bool done = false;
    s_stream << "* " << user_id << " ";
    target = s_stream.str();
    
    string file_char;
    ifstream read;
    read.open(date);
    
    if (!read.is_open())
    {
        cout << "Error opening file.\n;";
        return;
    }

    if (read.is_open())
    {
        cout << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------";
        cout << "\n\nOffice: HSU-HS\n";
        cout << "System: CPSIC\n\n";
        cout << "Date: " << date;
        
        cout << "\n\n";
        cout << setw(129) << "-------------------------------------------------------------------------------------";
        cout << endl << setw(88) << date << "  SCHEDULE" << endl;
        cout << setw(129) << "-------------------------------------------------------------------------------------";
        
        cout << "\n\n\t\t\t\t\t";
        for (int i = 0; i < 12; i ++)
        {
            cout << apt_times[i] << "\t\t";
        }
        
        char temp[25];
        
        cout << endl << endl;;
        
        while (getline(read, file_char))
        {
            if (file_char == target)
            {
            
                if (file_char == "* 1 ")
                    cout << "Doc/Nurse 1:\t\t";
                else if (file_char == "* 2 ")
                    cout << "Doc/Nurse 2:\t\t";
                else if (file_char == "* 3 ")
                    cout << "Doc/Nurse 3:\t\t";
                else if (file_char == "* 4 ")
                    cout << "Counselor 1:\t\t";
                else if (file_char == "* 5 ")
                    cout << "Counselor 2:\t\t";
            
                found = true;
            }
            
            if (file_char == "\n")
                cout << endl << endl;
            
            if (found)
            {
                strcpy(temp, file_char.c_str());
            
                if (temp[0] == '-')
                {
                    cout << file_char.substr(10);
                    cout << "\t\t";
                }
                else if (temp[0] == '+')
                {
                    cout << "x\t\t\t";
                    
                }
                else if (temp[0] == '#')
                {
                    done = true;
                }
            }
            
            if (done)
            {
                break;
            }
        }
        
        if (!found)
        {
            cout << setw(107) << "You have no scheduled appointments today.";
        }
    
        cout << endl << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        
        read.close();
        
    }
    else
    {
        cout << "ERROR: Could not open Schedule.\n";
        return;
    }

}

void schedule::printMasterSchedule()
{
    string date = __DATE__;
    
    printMasterSchedule(date);
}

void schedule::printMasterSchedule(string date)
{
    string file_char;
    ifstream read;
    read.open(date);
    
    if (!read.is_open())
    {
        cout << "Error opening file.\n;";
        return;
    }

    
    if (read.is_open())
    {
        cout << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------";
        cout << "\n\nOffice: HSU-HS\n";
        cout << "System: CPSIC\n\n";
        cout << "Date: " << date;
        
        cout << "\n\n";
        cout << setw(129) << "-------------------------------------------------------------------------------------";
        cout << endl << setw(88) << date << "  SCHEDULE" << endl;
        cout << setw(129) << "-------------------------------------------------------------------------------------";
        
        cout << "\n\n\t\t\t\t\t";
        for (int i = 0; i < 12; i ++)
        {
            cout << apt_times[i] << "\t\t";
        }
        
        char temp[25];
        
        cout << endl << endl;;
        
        while (getline(read, file_char))
        {
            if (file_char == "* 1 ")
                cout << "Doc/Nurse 1:\t\t";
            else if (file_char == "* 2 ")
                cout << "Doc/Nurse 2:\t\t";
            else if (file_char == "* 3 ")
                cout << "Doc/Nurse 3:\t\t";
            else if (file_char == "* 4 ")
                cout << "Counselor 1:\t\t";
            else if (file_char == "* 5 ")
                cout << "Counselor 2:\t\t";
            else if (file_char == "\n")
                cout << endl << endl;
            
            strcpy(temp, file_char.c_str());
            
            if (temp[0] == '-')
            { cout << file_char.substr(10);
                cout << "\t\t";
            }
            else if (temp[0] == '+')
            { cout << "x\t\t\t"; }
            else if (temp[0] == '#')
            { cout << endl; }
        
        }
        
        cout << endl << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        
        read.close();
        
    }
    else
    {
        cout << "ERROR: Could not open Schedule.\n";
        return;
    }
}
