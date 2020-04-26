#include "bill.h"
#include "schedule.h"
#include <iostream>
#include <iomanip>
using namespace std;

/*
	bill.cpp
	Declaration file for the class Bill.
*/

void Bill::setBill(double amt, schedule issue) {
	amount = amt;
	unpaidTotal = amt;
	issueDate = issue.getDate();
}

void Bill::addToBill(double amt, schedule issue) {
	amount += amt;
	unpaidTotal = amount - paidTotal;
	issueDate = issue.getDate();
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