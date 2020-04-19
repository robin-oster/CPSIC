#pragma once
/*
	bill.h
	Declaration file for class Bill
*/
#include <iostream>
using namespace std;
/**
	Author Jake Davis jdavi205@kent.edu
	@author Matthew Oster moster@kent.edu
*/

#include "schedule.h"

class Bill {
public:

	/** Constructor */
	Bill(): amount(0), issueDate(""), paidDate(""), paidTotal(0), unpaidTotal(0), paid(false) {}

	void setBill(double amt, schedule issue); /*!<Set the amount, issueDate, and unpaid total.*/
	void addToBill(double amt, schedule issue) { amount += amt; unpaidTotal += amt; issueDate = issue.getDate(); }
	void showBill();

	/*
		Sets bill to paid, provided the correct payment information is recieved.
	*/
	void payBill(double amt);

	// Accessor methods
	double getAmount() { return amount; }
	string getDate() { return issueDate; }
	string getPaidDate() { return paidDate; }
	double getPaidTotal() const { return paidTotal; }
	double getUnpaidTotal() { return unpaidTotal; }
	bool getPaymentStatus() { return paid; }

private:
	double amount; //Total amount of the individual bill, depending on ksuPatient
	string issueDate; //Date of the bill being issued
	string paidDate; // Date of the bill being paid
	double paidTotal; //Total amount paid to either the Health or Counseling service
	double unpaidTotal; //Total amount to be paid to either the Health or Counseling service
	bool paid; //Checks whether a bill has been paid (true) or unpaid (false)

};