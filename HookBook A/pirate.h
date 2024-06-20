#ifndef __PIRATE_H__
#define __PIRATE_H__

#include <stdio.h>

/*
Header file for pirate for assignment HookBook assignments in CPSC 223 FA2023.

Author: Alan Weide

TO STUDENT: You may add to this file, but do not change anything that is
    already here!
Modified by: Kemi Omoniyi on 10/6
Changelog: 
*/
/**
 * Type of a pirate.
 */
typedef struct pirate_instance_t pirate;

/**
 * Allocates enough memory for a pirate, and returns a pointer to the newly-
 *  allocated memory.
 */
pirate *pirate_create();

/**
 * Reads a pirate profile from input. Assumes that the input cursor is at the
 *  beginning of a pirate profile (otherwise, its behavior is undefined).
 *
 * Returns a pointer to a pirate created from the profile in input.
 *
 * This function consumes a blank line after the end of the current profile
 *  before returning, meaning that after this function is done, the input
 *  cursor is either at the end of the input file or at the beginning of the
 *  next pirate profile.
 */
pirate *pirate_read(FILE *input);

/**
 * Prints a pirate's profile to output in conformance with the output
 *  specification in the README.
 */
void pirate_print(const pirate *p, FILE *output);

/**
 * Returns the name of the pirate.
 */
const char *pirate_name(const pirate *p);

/**
 * Sets the name of a pirate.
 */
void pirate_set_name(pirate *p, const char *name);

/**
 * Compares two pirates, returning a negative number, zero, or a positive
 *  number as pirate a "comes before", is equal to, or "comes after" pirate b.
 */
int pirate_compare(pirate *a, pirate *b);

/**
 * Frees all memory associated with this pirate. This function claims ownership
 *  of p.
 */
void pirate_destroy(pirate *p);

#endif
