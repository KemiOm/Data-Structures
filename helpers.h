#ifndef __HELPERS_H__
#define __HELPERS_H__
// #Author: Kemi Omoniyi ato22
/*
Interface for helper functions for Game of Life assignment for CPSC 223 Fall 2023.

Author: Alan Weide

TO STUDENT: You may add to this file, but do not change anything that is already here!
Remember, this is a header file: there should be no function bodies here, only prototypes.
Modified by: Kemi Omoniyi on September 19
Changelog: [what you added to this file]
*/

#include <stdlib.h>

void print_initial(int field[], size_t size);

void print_generation(int field[], unsigned int gen, size_t size);

#endif