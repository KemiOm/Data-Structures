/* KEMI OMONIYI PSET 5 11/17/2023
 * LinkedList.cpp
 * CPSC 223 Pset 5
 *
 * Implementation for Linked List of GNHTA Stations
 * TO STUDENT: Don't forget to remove // TODO when you submit!
 *
 * Author: [Kemi Omoniyi]
 */

#include "LinkedList.h"
using namespace std;

// Default constructor
LinkedList::LinkedList()
{
    head = nullptr;
    currPos = nullptr;
    length = 0;
}

// Destructor
LinkedList::~LinkedList()
{
    makeEmpty();
}

// Assignment operator overload.
LinkedList &LinkedList::operator=(const LinkedList &rhs)
{
    // this is a linked list
    if (this == &rhs)
    {
           return *this;
    }
    // i"m basically reassigning where my pointer is pointing too
    NodeType* temp = head;
    while(head != nullptr)
    {
        temp = head;
        this->head = head->next;
        // delete within while loop
        delete temp;
    }
    this->length = rhs.length;
    currPos = nullptr;
    if (rhs.currPos == nullptr)
    {
        this->head = nullptr;
    }
    else 
    {
        // create new nodes 
        head = new NodeType();
        head->info = rhs.head->info;
        head->next = nullptr;
        NodeType* current = head;
        NodeType* original = rhs.head;
        while (original->next != nullptr)
        {
            current->next = new NodeType();
            current->next->info = original->next->info;
            current->next->next = nullptr;
            current = current->next;
            original = original->next;
        }
    }
     return *this;
}

// Copy constructor
LinkedList::LinkedList(const LinkedList &other)
{
    // check head is not null and then create a new hode 
    if (other.head == nullptr)
    {
        this->head = nullptr;
    }
    // set up before while 
    this->length = other.length;
    this->head = new NodeType();
    this->head->info = other.head->info;
    this->head->next = nullptr;
    NodeType* current = this->head;
    NodeType* original = other.head;
    while (original->next != nullptr)
    {
        if (current->info.isEqual(other.currPos->info))
        {
            this->currPos = current;
        }
        // copy the info make sure they match 
        // store a reference 
        current->next = new NodeType;
        current->next->next = nullptr;
        current->next->info = original->next->info;
        current = current->next;
        original = original->next;
    // check if info is equal at each step if they are assign current values to the other one 
    // call isEqual multiple times 
    }
}
// PURPOSE: RETURN LENGTH OF LINKED LIST
int LinkedList::getLength() const
{
    return length;
}
// CHECK TO SEE IF CURRENT POS IS NULL
bool LinkedList::isCurrPosNull() const
{
    return (currPos == nullptr);
}
// INSERT STATION AT FRONT OF LINKED LIST 
void LinkedList::insertStation(Station s)
{
    NodeType* newNode = new NodeType;
    newNode->info = s;  
    newNode->next = this->head; 
    this->head = newNode;
    length++;
}
// REMOVE STATION PROVIDED FROM LINKED LIST 
void LinkedList::removeStation(Station s)
{
 // edge case if the first one is the one I want to iterate through 
    NodeType *current = this->head;
    NodeType *prev = nullptr;
   
    while (current != nullptr && !current->info.isEqual(s))
    { 
        prev = current;
        current = current->next;
    } 
    if (current != nullptr)
    {
        if (prev == nullptr)
        {
            head = current->next;
        }
        // INSTRUCTED TO RESET CURR POS IN THI CASE 
        else if (current == currPos)
        {
            resetCurrPos();
            prev->next = current->next;
        }
        else 
        {
            prev->next = current->next;
        }
    }
    delete current;
    length--; 

}

Station LinkedList::getNextStation()
{
    if (this->head == nullptr)
    {
        return Station();
    }
    if (currPos == nullptr) 
    {
        currPos = this->head->next;

        return this->head->info;  
    }
    // Get the Station at currPos
    Station currentStation = currPos->info;

    // Move currPos to the next station
    currPos = currPos->next;

    return currentStation;
}

void LinkedList::resetCurrPos()
{
   currPos = nullptr;
}

void LinkedList::makeEmpty()
{
    NodeType* current = this->head;
    while (current != nullptr)
    {
        NodeType* temp = current->next;
        delete current;
        current = temp;
    }
    this->head = nullptr;
    length = 0;

}

void LinkedList::print(ostream &out)
{
    NodeType* current = this->head;
    int decrement = length - 1;
    while (current != nullptr) 
    {
        // call print function
        current->info.print(out);
    
        // Print the number of remaining stops with length 
        out << " " << decrement;
        // Check if there is a next station
        if (current->next != nullptr)
        {
            out << " == ";
        }
        else 
        {
            out << endl;
        }
        current = current->next;
        decrement--;
    }
}
