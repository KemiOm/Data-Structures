/* KEMI OMONIYI PSET 3 10/20/2023 */
#ifndef __SKILLS_LIST_H__
#define __SKILLS_LIST_H__
#include <stdlib.h>
#include <stdio.h>

/*
Header file for skills list for Hookbook assignments for CPSC 223 Fall 2023.

Author: Kemi Omoniyi
*/

/**
 * Type of a list of skills, as an opaque struct.
 */

typedef struct skills_list_instance_t skills_list;
typedef struct list_node node;
/** 
 * Creating a linked list
 * Allocate space for a `struct implementation`
 * Set the `head` pointer to `NULL`
*/
skills_list *skill_list_create();
// Returns the number of elements in lst
int skill_list_length(skills_list *lst);
// get skills by name 
node* get_skill_by_name(skills_list *list, const char *name);

// Function to access a skill at a particular index
node* get_skill_at_index(skills_list *list, size_t index);

void skill_list_insert(struct skills_list_instance_t *lst, const char *name);

// Function to remove a skill 
void remove_skill(skills_list *list, const char *name);

// Function to implement a custom type to track additional data about a skill
//void set_skill_data(skills_list *list, const char *name, SkillData additional_data);

int skills_repeat(const struct skills_list_instance_t *skillsList);
//  sort function altogether—perhaps by maintaining a sorted order as you insert each skill or by selecting the skills in order from an unsorted list when it comes time to print them.


// Frees the memory allocated by lst
void skill_list_destroy(skills_list *lst);

/**
 *  Printing a list
 * Print the head node
 * Print the rest of the list
*/
void list_print(skills_list *lst, FILE *out);


#endif