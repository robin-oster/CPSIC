#pragma once
/*
	bill.h
	Declaration file for class Bill
*/

#ifndef BILL_H
#define BILL_H


#include <iostream>
using namespace std;
/**
	Author Jake Davis jdavi205@kent.edu
	@author Matthew Oster moster@kent.edu
*/

//#include "schedule.h"
class schedule;

class Bill {
public:

	/** Constructor */
	Bill(): amount(0), issueDate(""), paidDate(""), paidTotal(0), unpaidTotal(0), paid(false) {}
	Bill(const Bill& src): amount(src.amount), issueDate(src.issueDate), paidDate(src.paidDate), paidTotal(src.paidTotal), 
		unpaidTotal(src.unpaidTotal), paid(src.paid){}

	void setBill(double amt, schedule issue); /*!<Set the amount, issueDate, and unpaid total.*/
	void setAmount(double amt) { amount = amt; }
	void setPaidTotal(double amt) { paidTotal = amt; if (paidTotal == amt) paid = true; }
	void addToBill(double amt, schedule issue);
	
	void showBill();

	/*
		Sets bill to paid, provided the correct payment information is recieved.
	*/
	void payBill(double amt);

	// Accessor methods
	double getAmount() const { return amount; }
	string getDate() const { return issueDate; }
	string getPaidDate() const { return paidDate; }
	double getPaidTotal() const { return paidTotal; }
	double getUnpaidTotal() const { return unpaidTotal; }
	bool getPaymentStatus() const { return paid; }

private:
	double amount; //Total amount of the individual bill, depending on ksuPatient
	string issueDate; //Date of the bill being issued
	string paidDate; // Date of the bill being paid
	double paidTotal; //Total amount paid to either the Health or Counseling service
	double unpaidTotal; //Total amount to be paid to either the Health or Counseling service
	bool paid; //Checks whether a bill has been paid (true) or unpaid (false)

};

#endif