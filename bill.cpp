#include "bill.h"
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

void Bill::payBill(double amt) {
	if (paid == false) {
		paidTotal += amt;
		unpaidTotal -= amt;
		if (paidTotal >= amount) {
			paid = true;
			paidDate = "today";
		}
	}
	else cout << "\nYour bill is aleady paid in full.";
}