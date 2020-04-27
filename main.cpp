
#pragma once

/**
	main.cpp
	Need a main to make a makefile
*/

#include "User.h"
#include "systemControl.h"
#include "schedule.h"
#include "statistics.h"
#include "ksuSystemAccess.h"
#include "bill.h"
#include "coronaInfo.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <random>
using namespace std;

/**
	@author 	Jake Davis	jdavi205@kent.edu	
	@author 	Jacob Gojkov	jgojkov@kent.edu
	@author	Matthew Oster	moster@kent.edu
	@author	Daniel Stephan	dstepha3@kent.edu
*/

int main()
{
	ofstream os;
  
  schedule schedule;
	systemControl sys;
	Statistics stats;
	coronaInfo c_info;
	ksuSystemAccess ksuAccess(os);
	User* mainUser = new User(); 
	bool studentStatus;
	bool log_out = false;
	int prevCoronaCount = 0;
    
	srand(time(NULL)); // for coronaInfo
	sys.addStatisticSnapshot(stats); // initial info

	do {
		c_info.updateOhioCount();
		c_info.updateUSCount();
		if (c_info.getOhioCount() > prevCoronaCount) {
			ksuAccess.generateAlert(c_info.getOhioCount() - prevCoronaCount);
		}
		prevCoronaCount = c_info.getOhioCount();
		sys.addCoronaSnapshot(c_info);

		log_out = false;
		sys.facultyAccess = false;
		studentStatus = sys.logOn(mainUser);

		stats.setPatientCount(sys.getPatientCount());

		if (sys.facultyAccess == false) {
			ksuPatient patientUser(*mainUser, studentStatus);
			unsigned int choice;

			do {
				do {
					cout << "\nWelcome to the KSU-HS CPSIC. What would you like to do?\n";
					cout << "Enter 1 to make an appointment.\n";
					cout << "Press 2 to view your appointments.\n";
					cout << "Press 3 to reschedule an appointment.\n";
					cout << "Enter 4 to view outstanding bills.\n";
					cout << "Enter 5 to make a payment on a bill.\n";
					cout << "Enter 6 to log out of the system.\n";
					cout << "Input: ";
					cin >> choice;

					if (choice > 6) cout << "Invalid input. Try again.\n";
				} while (choice > 6);

				if (choice == 1) {
                    patientUser.registerAppointment(schedule);
				}
				else if (choice == 2) {
                    patientUser.viewAppointment(schedule);
				}
				else if (choice == 3) {
					//reschedule appointments
				}
				else if (choice == 4) {
					patientUser.showCounselorBill();
					patientUser.showPractitionerBill();
				}
				else if (choice == 5) {
					int billChoice;
					auto userIt = find(sys.registeredPatients.begin(), sys.registeredPatients.end(), patientUser);

					cout << "Make a payment on which bill?\n";
					cout << "Enter 1 for practitioner bill, 2 for counseler bill: \n";
					do {
						cin >> billChoice;
						if (billChoice != 1 && billChoice != 2) cout << "Invalid input. Try again.\n";
					} while (billChoice != 1 && billChoice != 2);

					double paymentAmount;
					if (billChoice == 1) {
						do {
							cout << "Pay how much on practitioner bill?: ";
							cin >> paymentAmount;
							if (paymentAmount < 0.01) cout << "Invalid input.Try again.\n";
						} while (paymentAmount < 0.01);
						patientUser.getPractitionerBill()->payBill(paymentAmount);

						userIt->getPractitionerBill()->setPaidTotal(userIt->getPractitionerBill()->getPaidTotal() + paymentAmount);

					}
					else {
						do {
							cout << "Pay how much on counselor bill?: ";
							cin >> paymentAmount;
							if (paymentAmount < 0.01) cout << "Invalid input.Try again.\n";
						} while (paymentAmount < 0.01);
						patientUser.getCounselorBill()->payBill(paymentAmount);
						userIt->getCounselorBill()->setPaidTotal(userIt->getCounselorBill()->getPaidTotal() + paymentAmount);
					}
				}
				else if (choice == 6) 
					log_out = sys.logOff();
			} while (log_out == false);
		}
		else {
			hsFaculty facultyUser(*mainUser);
			unsigned int choice;

			do {

				do {

					cout << "\nWelcome to the KSU-HS CPSIC. What would you like to do?\n";
					cout << "Enter 1 to view your schedule.\n";
					cout << "Press 2 to edit your schedule.\n";
					cout << "Enter 3 to view statistical information.\n";
					cout << "Enter 4 to update a patient record.\n";
					cout << "Enter 5 to view a patient record.\n";
					cout << "Enter 6 to view department and total earnings.\n";
					cout << "Enter 7 to log out of the system.\n";
					cout << "Input: ";
					cin >> choice;

					if (choice > 7) cout << "Invalid input. Try again.\n";
				} while (choice > 7);

				if (choice == 1) {
					facultyUser.viewSchedule(schedule);
				}
				else if (choice == 2) {
					facultyUser.editSchedule(schedule);
				}
				else if (choice == 3) {
					char statChoice = ' ';

					cout << endl;
					facultyUser.showStats(c_info, stats);
					cout << "\nVisualize statistics? (Y/N): ";
					cin >> statChoice;
					while (toupper(statChoice) != 'Y' && toupper(statChoice) != 'N') {
						cout << "Invalid input. Try again: ";
						cin >> statChoice;
					}
					if (toupper(statChoice) == 'Y') sys.visualizeStats();
					cout << endl;
				}
				else if (choice == 4) {
					facultyUser.updateRecord(stats, sys);
					sys.addStatisticSnapshot(stats);
					//update stats accordingly
				}
				else if (choice == 5) {
					facultyUser.viewRecord(sys);
				}
				else if (choice == 6) {
					sys.calculateEarnings();
					cout << "\n==============================================================================";
					cout << fixed << setprecision(2) << setfill('0');
					cout << "\nTotal Practitioner Earnings: " << "$" << sys.getPractitionerEarnings();
					cout << "\nTotal Counselor Earnings: " << "$" << sys.getCounselorEarnings();
					cout << "\nTotal KSU-HS Earnings: " << "$" << sys.getTotalEarnings();
					cout << "\n=============================================================================\n\n";
				}
				else if (choice == 7)
					log_out = sys.logOff();
			} while (log_out == false);
		}
	} while (true);
}
