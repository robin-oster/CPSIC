
//schedule.cpp

//Definition file for schedule class

//include necessary directories
#include <sstream>
#include <string>
#include <cstring>

#include <cstdio>
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
}

schedule::schedule(const schedule& src) {
    string current_date;
    stringstream s_stream;
    s_stream << __DATE__;
    current_date = s_stream.str();
}

//printAppt function
//Displays appointment
void schedule::printAppt() {
    cout << "\nYour current appointment is on ";
    cout << appointment.date << " at " << appointment.timeslot << "." << endl;
}

//get and set functions
string schedule::getDate() {
	return appointment.date;
}
string schedule::getTimeslot() {
	return appointment.timeslot;
}
int schedule::getPatient() {
	return appointment.patient;
}
int schedule::getStaff() {
	return (appointment.faculty);
}

void schedule::setDate(string date) {
	appointment.date = date;
}
void schedule::setTimeslot(string timeslot) {
	appointment.timeslot = timeslot;
}
void schedule::setPatient(int patient_id) {
	appointment.patient = patient_id;
}
void schedule::setStaff(int faculty_id) {
	appointment.faculty = faculty_id;
}

//saveAppt function
//saves appointment to schedule
void schedule::saveAppt(int student_id, string date, string time, int ID)
{
    stringstream s_stream1, s_stream2;
    bool found = false;
    s_stream1 << "* " << ID << " ";
    string target_id;
    string target_time;
    target_id = s_stream1.str();
    
    s_stream2 << "+ " << time;
    target_time = s_stream2.str();
    
    string file_char;
    string buffer;
    string temp_file = "temp";
    ifstream read;
    ofstream write;
    read.open(date);
    write.open(temp_file);
    
    
    
    if (!read.is_open())
    {
        cout << "Error opening file.\n;";
        return;
    }
    
    char temp[25];
    
    cout << endl << endl;
    
    while (getline(read, file_char))
    {
        if (file_char == target_id)
        {
            found = true;
            write << file_char << "\n";
        }
        
        else if (!found && file_char != target_id)
        {
            write << file_char << "\n";
        }
        
        if (file_char == "\n")
        {
            write << file_char << "\n";
            cout << endl << endl;
        }
        
        if (found)
        {
            strcpy(temp, file_char.c_str());
            
            if (file_char != target_time && file_char != target_id)
            {
                write << file_char << "\n";
            }
            else if (file_char == target_time)
            {
                write << "- " << time << " : " << student_id << "\n";
                found = false;
            }
            

        }
    }
    
    read.close();
    write.close();
    
    read.open(temp_file);
    write.open(date);
    
    buffer = "\0";
    
    while (getline(read, buffer))
    {
        write << "\n" << read.rdbuf();
    }
    
    read.close();
    write.close();
    
    if (remove("temp") == 0)
    {
        cout << "Appointment made.\n\n";

        setPatient(student_id);
        setStaff(ID);
        setDate(date);
        setTimeslot(time);
        
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

    cout << "Enter 3 for a specific date.\nInput: ";
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
            edit << "\n- " << apt_times[i] << " : OFF";
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
    bool found = false;
    bool done = false;
    s_stream << "* " << user_id << " ";
    string target;

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
                    cout << "\t\t\t";
                }
                else if (temp[0] == '+')
                {
                    cout << "\t\t\t";
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
            {
                cout << "x\t\t\t";
            }
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
