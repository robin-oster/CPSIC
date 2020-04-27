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

	cout << "=========================================================\n\n";

}

void Bill::payBill(double amt) {
	if (paid == false) {
		paidTotal += amt;
		if (paidTotal > amount) paidTotal = amount;
		unpaidTotal -= amt;
		if (unpaidTotal < 0) unpaidTotal = 0;
		if (paidTotal >= amount) {
			paid = true;
			paidDate = "";
		}
	}
	else cout << "Your bill is aleady paid in full.\n";
}