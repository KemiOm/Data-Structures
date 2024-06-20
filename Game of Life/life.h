#ifndef __LIFE_H__
#define __LIFE_H__
// #Author: Kemi Omoniyi ato22
/*
Interface for Game of Life assignment in CPSC 223 Fall 2023.

Author: Alan Weide

TO STUDENT: You may add to this file, but do not change anything that is already here!
Remember, this is a header file: there should be no function bodies here, only prototypes.
Modified by: [Kemi Omoniyi] on [September 19]
Changelog: [what you added to this file]
*/

#include <stdbool.h>
#include <stdlib.h>

bool isAlive(int field[], size_t i, size_t size);

bool shouldDie(int field[], size_t i, size_t size);

#endif