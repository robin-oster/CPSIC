
#pragma once

/**
    User.h
    Declaration file for class User.
*/

#ifndef USER_H
#define USER_H

//#include "schedule.h"
#include "coronaInfo.h"
#include <string>
#include <iostream>
using namespace std;

/**
 
    @author Daniel Stephan dstepha3@kent.edu
	@author Matthew Oster moster@kent.edu
*/

class User
{
public:
	
	User();
	User(User& source);
	User operator=(User& source);

    /**
     Displays current statistics of Coronavirus cases in Ohio & USA.
     
     @param statistics
     */
    

	void showStats(coronaInfo stats)
    {
		cout << "Coronavirus cases in Ohio:\t" << /*cases <<*/ endl;
		cout << "Coronavirus cases in USA:\t" << /*cases <<*/ endl;
	}


	bool operator==(User target);

	int getID() const { return ID; }
	string getName() const { return name; }
	string getPassword() const { return password; }
	void setID(const int id) { ID = id; }
	void setName(const string theName) { name = theName; }
	void setPassword(const string pass) { password = pass; }

private:
    int ID; /**< Identification number unique to each patient, assigned by the school. */
    string name; /**< Name of user. */
	string password;
};

#endif
