/* KEMI OMONIYI PSET 5 11/17/2023
 * NodeType.h
 * CPSC 223 Pset 5
 *
 *
 * Small struct that is part of a Linked List class.
 */

#ifndef __NODETYPE_H__
#define __NODETYPE_H__

#include "Station.h"
using namespace std;

struct NodeType
{
    Station info;
    NodeType *next;
};

#endif
