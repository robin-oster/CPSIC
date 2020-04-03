
#pragma once

/**
    User.h
    Declaration file for class User.
*/

#ifndef USER_H
#define USER_H

#include "schedule.h"
#include "statistics.h"
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
    void showStats(statistics)
    {
        cout << "Coronavirus cases in Ohio:\t" << /*cases*/ << endl;
        cout << "Coronavirus cases in  USA:\t" << /*cases*/ << endl;
    }
  
private:
    int ID; /**< Identification number unique to each patient, assigned by the school. */
    string name; /**< Name of user. */
    
};

#endif
