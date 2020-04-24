#pragma once
/*
	ksuSystemAccess.h
	Declaration file for class ksuSystemAccess.
*/

#ifndef KSU_SYSTEM_ACCESS_H
#define KSU_SYSTEM_ACCESS_H

#include "ksuPatient.h"
#include <vector>

/**
	@author Matthew Oster moster@kent.edu
*/

class ksuSystemAccess {
public:
	ksuSystemAccess(ofstream& out_stream): o_str(out_stream) {}

	/**
	Carries out the process of preparing, packaging, and sending an alert to the KSU website and Flash Alerts.

	@param amt The number of new cases of Coronavirus discovered.
	*/
	void generateAlert(int amt);


private:
  /**
	Helper function for generateAlert(). Responsible for publishing the details of the alert to the KSU website.

	@param amt The number of new cases of Coronavirus discovered.
	*/
	void notifyKSU(int amt);
 
  /**
	Helper function for generateAlert(). Responsible for publishing the details of the alert to Flash Alerts.

	@param amt The number of new cases of Coronavirus discovered.
	*/
	void notifyFlashAlerts(int amt);
	
	ofstream& o_str;
  };
	
  #endif
