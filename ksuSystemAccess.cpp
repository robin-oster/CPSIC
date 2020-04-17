/*
        ksuSystemAccess.cpp
        Declaration file for class ksuSystemAccess.
*/

#include "ksuSystemAccess.h"

/**
        @author Matthew Oster moster@kent.edu
*/

void ksuSystemAccess::generateAlert(){
	notifyKSU();
	notifyFlashAlerts();
}

void ksuSystemAccess::notifyKSU(){
	// Publish the following to the KSU website
	cout << "ALERT: Report of new Coronavirus cases.\n";
	for (auto i = alertInfo.begin(); i != alertInfo.end(); i++)
		cout << i->getName() << endl;
}

void ksuSystemAccess::notifyFlashAlerts(){
	// Publish the following to the FlashAlerts
	cout << "ALERT: Report of new Coronavirus cases.\n";
	for (auto i = alertInfo.begin(); i != alertInfo.end(); i++)
		cout << i->getName() << endl;
}
