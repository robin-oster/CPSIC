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
	/**
	Carries out the process of preparing, packaging, and sending an alert to the KSU website and Flash Alerts.
	*/
	void generateAlert();

  	std::vector<ksuPatient> alertInfo; /*!< The collection of alert info to be published. */

private:
  /**
	Helper function for generateAlert(). Responsible for publishing the details of the alert to the KSU website.
	*/
	void notifyKSU();
 
  /**
	Helper function for generateAlert(). Responsible for publishing the details of the alert to Flash Alerts.
	*/
	void notifyFlashAlerts();
  };
	
  #endif
