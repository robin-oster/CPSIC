#include "bill.h"
#include "schedule.h"
#include <date.h>
#include <iostream>
#include <iomanip>
using namespace std;

/*
	bill.cpp
	Declaration file for the class Bill.
*/

void Bill::setBill(double amt, schedule issue) {
	const char* format = new const char('%d');
	ostringstream os;
	amount = amt;
	unpaidTotal = amt;
	date::to_stream(os, format, issue.getDate());
	issueDate = os.str();
}

void Bill::addToBill(double amt, schedule issue) {
	const char* format = new const char('%d');
	ostringstream os;

	amount += amt;

	amount = amt;
	unpaidTotal = amt;
	date::to_stream(os, format, issue.getDate());
	issueDate = os.str();
}

void Bill::showBill() {
	cout << fixed << setprecision(2) << setfill('0');
	cout << "==========================================================\n";
	cout << "Total Balance: $" << amount << endl;
	cout << "Issue Date: " << issueDate << endl;
	cout << "Paid Balance: $" << paidTotal << endl;
	cout << "Unpaid Balance: $" << unpaidTotal << endl;

	if (paidTotal >= amount)
		cout << "Paid Date: " << paidDate << endl;

	cout << "=========================================================\n";

}

void Bill::payBill(double amt) {
	if (paid == false) {
		paidTotal += amt;
		unpaidTotal -= amt;
		if (paidTotal >= amount) {
			paid = true;
			paidDate = "today";
		}
	}
	else cout << "Your bill is aleady paid in full.\n";
}