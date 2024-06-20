/* KEMI OMONIYI PSET 3 10/20/2023 */
#ifndef __PIRATE_LIST_H__
#define __PIRATE_LIST_H__

/*
Header file for pirate list for Hookbook assignments for CPSC 223 Fall 2023.

Author: Alan Weide

TO STUDENT: You may add to this file, but do not change anything that is
    already here!
Modified by: Kemi Omoniyi 10/16/2023
Changelog: added treasure_compare, vessel_compare, and name_compare 
*/

#include <stdlib.h>

#include "pirate.h"

/**
 * Type of a list of pirates, as an opaque struct.
 */
typedef struct pirate_list_instance_t pirate_list;

/**
 * Allocate memory for a new pirate_list and return a pointer to it.
 *
 * The comparison function returns a negative number, zero, or a positive number
 *  as the first argument "comes before", is the same as, or "comes after" the
 *  second.
 */
pirate_list *list_create(int (*comp)(const void *, const void *));

/**
 * Return the index of the pirate with the same name as p, or a value greater
 *  than or equal to the length of the list if the pirate is not in the list.
 *
 * Ownership of p is not changed.
 */
size_t list_index_of(pirate_list *pirates, pirate *p);

/**
 * Only if there is no pirate in the list with the same name as p, insert
 *  pirate p into the list at index idx by copying the pointer, shifting the
 *  latter part of the list one "slot" to the right.
 *
 * Assumes 0 <= idx <= [the length of the list] (otherwise its behavior is
 *  undefined).
 *
 * If there is a pirate in the list with the same name as p, do nothing, and
 *  return p (the pirate that was not inserted).
 *
 * If the pirate was inserted into the list, return NULL.
 *
 * If p is added to the list, the list claims ownership of the pirate pointed
 *  to by p; otherwise ownership remains with p.
 */
pirate *list_insert(pirate_list *pirates, pirate *p, size_t idx);

/**
 * Remove the pirate from the list with the same name as p, and return a
 *  pointer to it.
 * If there is no pirate in the list with the same name as p, return NULL.
 *
 * The caller of this function is responsible for freeing the returned pirate
 *   if it is not NULL.
 */
pirate *list_remove(pirate_list *pirates, pirate *p);

/**
 * Return a pointer to the pirate pointed to by index idx in the list, or NULL
 *  if idx is not a valid index (i.e., it is >= the length of the list).
 *
 * Ownership of the pirate remains with the list.
 */
pirate *list_access(pirate_list *pirates, size_t idx);

/**
 * Sort the list of pirates according to the order defined when this list was
 * created.
 */
void list_sort(pirate_list *pirates);

int name_compare(const void*, const void *);
int vessel_compare(const void *, const void *);
int treasure_compare(const void *, const void *);


/**
 * Return the number of pirates in the list.
 */
size_t list_length(pirate_list *pirates);

/**
 * Free all memory associated with the list, including the pirates in the list.
 */
void list_destroy(pirate_list *pirates);
#endif