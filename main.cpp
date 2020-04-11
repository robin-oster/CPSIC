
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
	
	systemControl E;
	User mainUser;
	E.logOn();


	string words = "ope.";

	cout << setw(30) <<  words << endl << endl;

	return 0;
}
