/* KEMI OMONIYI PSET 5 11/17/2023
 * LinkedList.h
 * CPSC 223 Pset 5
 *
 * Interface for Linked List of GNHTA Stations
 *
 * TO STUDENT: You may ONLY modify this file by adding private members!
 * The only exception is the TODO on line 29, which is part of an optional
 *  additional activity.
 */

#include "NodeType.h"
#include "Station.h"
#include <fstream>

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

/**
 * Class for a linked list of Stations. The (abstract) state of a LinkedList is
 *  a sequence of Stations.
 * There are two (abstract) properties of a LinkedList:
 *      this.length
 *          the number of Stations in the list
 *      this.currPos
 *          a cursor into the list, which is NULL if it has never been used or
 *          if it has just been reset or if it has traveled past the end of the
 *          list.
 *
 * TODO: The above comment describes the abstract state of a list. The concrete
 *  state (i.e., the private members) may differ slightly, significantly, or
 *  not at all. Describe the "abstraction function" for this list: how does a
 *  particular set of values of the private members translate to an abstract
 *  value? Importantly: in which order do the nodes of the linked list map to
 *  the sequence in the abstract state?
 * NOTE: This is part of an optional additional activity.
 *
 * Abstraction Function: [describe abstraction function here]
 */
class LinkedList
{
public:
    /**
     * Default constructor.
     *
     * Creates a new, empty LinkedList with NULL currPos
     */
    LinkedList();

    /**
     * Destructor.
     * Frees all memory owned by `this`.
     */
    ~LinkedList();

    /**
     * Assignment operator overload. Performs a deep copy of the list referred
     *  to by `rhs` into `this`.
     *
     * @param rhs reference to the list on the right-hand side of the
     *  assignment statement
     * @return a reference to `this`, a copy of `rhs`.
     */
    LinkedList &operator=(const LinkedList &rhs);

    /**
     * Copy constructor.
     *
     * Creates a new list that is a deep copy of `other`.
     *
     * @param other reference to the list to copy to create `this`
     */
    LinkedList(const LinkedList &other);

    /**
     * Inserts a station at the front of `this`. After this function:
     *  `this.stations` is `s` followed by the Stations that were in
     *  `this.stations` before this function was called, and
     *  `this.currPos` is unchanged
     *
     * @param s the Station to insert.
     */
    void insertStation(Station s);

    /**
     * Removes from `this` the first Station in `this` that is equal to `s`.
     *
     * This method removes the first Station equal to `s` from `this`, and
     *  deallocates the memory owned by the removed Station as well as any
     *  memory allocated by `this` to manage the Station.
     * If the removed Station is `this.currPos`, then the method resets
     *  `this.currPos`.
     * If `s` is not in `this`, then the method does nothing (including not
     *  changing any state of `this`).
     *
     * @param s the Station to remove
     */
    void removeStation(Station s);

    /**
     * Removes all Stations from `this` and dellocates all memory owned by
     *  those Stations and all memory allocated by `this` to manage each
     *  Station.
     * This method resets `this.currPos`.
     */
    void makeEmpty();

    /**
     * Resets `this.currPos`.
     */
    void resetCurrPos();

    /**
     * Returns the station at `this.currPos` and advances `this.currPos` to the
     *  next station in the list.
     * If `this.currPos` is NULL, then this function behaves as though
     *  `this.currPos` was a pointer to the first station in the list.
     * If there are no stations in the list, the behavior of this function is
     *  undefined.
     *
     * @return the next Station in `this`
     */
    Station getNextStation();

    /**
     * Reports whether `this.currPos` is NULL.
     *
     * @return (this.currPos = nullptr)
     */
    bool isCurrPosNull() const;

    /**
     * Reports the number of Stations in `this`.
     *
     * @return the number of Stations in `this`
     */
    int getLength() const;

    /**
     * Prints `this` as a formatted list of Stations to the stream referenced
     *  by `out`.
     *
     * For each Station in `this`, proceeding sequentially, print the following
     *  for each of them:
     *  1. The name and accessibility level of the Station
     *  2. A single space
     *  3. The number of remaining stops in the list
     *  4. If there is a next station, the string " == " (note the space before
     *      and after the "train tracks" ==)
     *  5. If there is no next station, a single newline character
     *
     * If there are no Stations in `this`, print a single newline character.
     *
     * @param out the stream to which to print this list
     */
    void print(ostream &out);
/**created a private NodeType to store the current position 
 * which will be called in the linked.list.cpp
 * Also created a head pointer for our linkedList 
 * length to store the value of our LinkedList length
*/
private:
        NodeType *currPos;
        NodeType *head;
        int length;
};

#endif
