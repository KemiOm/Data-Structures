/* KEMI OMONIYI PSET 5 11/17/2023
 * Station.h
 * CPSC 223 Pset 5
 *
 * Interface for Station class
 *
 */

#ifndef __STATION_H__
#define __STATION_H__

#include <fstream>
#include <string>
using namespace std;

/**
 * Type representing a GNHTA Station. The state of a Station consists of:
 *  name
 *      the name of this station, a string
 *  access
 *      a boolean that is true if this station is accessible; false otherwise
 */
class Station
{
public:
    /**
     * Default constructor.
     * Creats a Station with name "NoName" and accessibility "false".
     */
    Station();

    /**
     * Parameterized constructor.
     * Creates a station with name `name` and accessibility `access`.
     *
     * @param name the name of the new Station
     * @param access the accessibility of the new Station
     */
    Station(string name, bool access);

    /**
     * Prints this Station's name and accessibility level to `out`.
     * Format of output is `this.name` followed by a single space, followed by
     *  the accessibility level of `this`, which is either 'A' (if this is
     *  accessible) or 'U' (if this is not accessible).
     *
     * @param out the stream to which to print this Station's information
     */
    void print(ostream &out);

    /**
     * Reports whether `this` Station is equal to `other`.
     * Two stations are equal if their name and accessibility levels are both
     *  equal.
     *
     * @param other the Station to which to compare `this`
     * @return (this = other)
     */
    bool isEqual(Station other);

    /**
     * Getter for `this` Station's accessiblity; implemented for you.
     *
     * @return this.access
     */
    bool getAccess()
    {
        return access;
    };

    /**
     * Getter for `this` Station's name; implemented for you.
     *
     * @return this.name
     */
    string getName()
    {
        return name;
    }

private:
    string name;
    bool access;
};

#endif
