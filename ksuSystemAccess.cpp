/*
        ksuSystemAccess.cpp
        Declaration file for class ksuSystemAccess.
*/

#include "ksuSystemAccess.h"

/**
        @author Matthew Oster moster@kent.edu
*/

void ksuSystemAccess::generateAlert(int amt){
	notifyKSU(amt);
	notifyFlashAlerts(amt);
}

void ksuSystemAccess::notifyKSU(int amt){
	// Publish the following to the KSU website
	o_str.open("notifyKSU.txt");

	if (!o_str.is_open()) {
		cout << "Output file stream to 'notifyKSU.txt' failed.\n";
		return;
	}

	o_str << "ALERT: KSU report of new Coronavirus cases.\n";
	o_str << amt << " new cases of Coronavirus discovered.\n";

	o_str.close();
}

void ksuSystemAccess::notifyFlashAlerts(int amt){
	// Publish the following to the FlashAlerts
	o_str.open("notifyFlashAlerts.txt");

	if (!o_str.is_open()) {
		cout << "Output file stream to 'notifyFlashAlerts.txt' failed.";
		return;
	}

	o_str << "ALERT: FlashAlert report of new Coronavirus cases.\n";
	o_str << amt << " new cases of Coronavirus discovered.\n";
	
	o_str.close();
}
