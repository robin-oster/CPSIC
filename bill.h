#pragma once
/*
	bill.h
	Declaration file for class Bill

*/
#include <iostream>
using namespace std;
/**
	Author Jake Davis jdavi205@kent.edu
*/

class Bill {
public:
	/*
		Constructor class to set bill.
	*/
	void setBill(double, string, bool);
	/*
		Retrieves variables from private; amount, issueDate, paidDate (if applicable), and paid.
	*/
	void getBill();
	/*
		Retrieves variable paidTotal.
	*/
	double getPaidTotal();
	/*
		Retrieves variable unpaidTotal.
	*/
	double getUnpaidTotal();
	/*
		Sets bill to paid, provided the correct payment information is recieved.
	*/
	void payBill();
private:
	double amount; //Total amount of the individual bill, depending on ksuPatient
	string issueDate; //Date of the bill being issued
	string paidDate; // Date of the bill being paid
	double paidTotal; //Total amount paid to either the Health or Counseling service
	double unpaidTotal; //Total amount to be paid to either the Health or Counseling service
	bool paid; //Checks whether a bill has been paid (true) or unpaid (false)
	
};
