
#pragma once

/**
	main.cpp
	Need a main to make a makefile
*/

#include "User.h"
#include "systemControl.h"

//#include “schedule.h”
//#include “statistics.h”
//#include “systemAccess.h”
//#include “bill.h”
//#include "coronaInfo.h"

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/**
	@author 	Jake Davis		jdavi205@kent.edu	
	@author 	Jacob Gojkov	jgojkov@kent.edu
	@author	Matthew Oster	moster@kent.edu
	@author	Daniel Stephan	dstepha3@kent.edu
*/

int main()
{

	/**
	 *
	 * This main does nothing.
	 *
	*/
	
	systemControl sys;
	User mainUser;
	sys.logOn();


	string words = "ope.";

	for (auto i = sys.registeredPatients.begin(); i != sys.registeredPatients.end(); i++)
		cout << *i;
	if (sys.facultyAccess == true) cout << "\nAccess Granted";
	else cout << "\nAccess denied";
	return 0;
}
