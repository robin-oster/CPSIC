
#pragma once

/**
    User.h
    Declaration file for class User.
*/

#ifndef USER_H
#define USER_H

#include "schedule.h"
//#include "statistics.h"
#include <string>
using namespace std;

/**
 
    @author Daniel Stephan dstepha3@kent.edu
*/

class User
{
public:
    /**
     Displays current statistics of Coronavirus cases in Ohio & USA.
     
     @param statistics
     */
    

	//void showStats(Statistics)
    // {
    //     cout << "Coronavirus cases in Ohio:\t" << /*cases*/ << endl;
    //     cout << "Coronavirus cases in  USA:\t" << /*cases*/ << endl;
    // }


	bool operator==(User target);

	void setID(int id) { ID = id; }
	void setPassword(string pass) { password = pass; }

private:
    int ID; /**< Identification number unique to each patient, assigned by the school. */
    string name; /**< Name of user. */
	string password;
};

#endif
