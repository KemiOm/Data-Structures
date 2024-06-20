/* KEMI OMONIYI PSET 5 11/17/2023
 * Station.cpp
 * CPSC 223 Pset 5
 *
 * Implementation of the Station class
 * TO STUDENT: Don't forget to remove // TODO before you submit!
 *
 * Author: [KEMI OMONIYI]
 */

#include "Station.h"

// Default Constructor (Implemented for you)
Station::Station()
{
    this->name = "NoName";
    this->access = false;
}
//PURPOSE: ASSIGN THE VALUES OF NAME AND ACCESS 
Station::Station(string name, bool access)
{
    this->name = name;
    this->access = access;
}

bool Station::isEqual(Station s)
{
    // TODO: Implement this
    return (this->name == s.getName()) && (this->access == s.getAccess());
}

void Station::print(ostream &outfile)
{
    if (this->access)
    {
        outfile << this->name << " A" ;
    }
    else if (!this->access)
    {
        outfile << this->name << " U" ;
    }

}
