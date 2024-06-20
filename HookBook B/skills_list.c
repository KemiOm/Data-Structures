/* KEMI OMONIYI  PSET 3 10/16/2023 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "skills_list.h"
/* 
Header file for skills list for Hookbook assignments for CPSC 223 Fall 2023.

Author: Kemi Omoniyi
*/

/**
 * Type of a list of skills, as an opaque struct.
 */
typedef struct list_node node;

struct list_node
{
    char *name;
    node *nextpointer;
    int counter;
}; 

struct skills_list_instance_t
{
    node *head;
};



/** 
 * Creating a linked list
 * Allocate space for a `struct implementation`
 * Set the `head` pointer to `NULL`
*/
skills_list *skill_list_create()
{
    skills_list *lst = malloc(sizeof(skills_list));
    lst->head = NULL;
    return lst; 
}

// PURPOSE: Returns the number of elements in lst
int skill_list_length(skills_list *lst)
{
    int length = 0;
    node *n = lst->head;
    while (n != NULL)
    {
        n = n->nextpointer;
        length++;
    }
    return length;
}
// PURPOSE: get skills by name 
node* get_skill_by_name(skills_list *list, const char *name)
{
    if ( list == NULL || name == NULL)
    {
        node *current = list->head;
        while (current != NULL) 
        {
        
        if (strcmp(current->name, name) == 0) 
        {
            return current;  
        }
        current = current->nextpointer;
        }

    }
    return NULL; 
}

// Function to access a skill at a particular index
node* get_skill_at_index(skills_list *list, size_t index)
{
    if (list == NULL || index < 0) 
    {
        return NULL;  
    }

    
    node *current = list->head;
    size_t count = 0;

    while (current != NULL && count < index) 
    {
        if (count == index )
        {
            return current;
        }
        current = current->nextpointer;
        count++;
    }

    if (count == index && current != NULL)
    {
        return current;
    }
    else
    {
        // Return NULL if the index is out of bounds
        return NULL;
    }
}
/*void skill_list_insert(struct skills_list_instance_t *lst, const char *name) {
    if (name == NULL || lst == NULL) {
        return;
    }

    // Check if the head is a duplicate
    if (lst->head != NULL && strcmp(name, lst->head->name) == 0) {
        lst->head->counter++;
        return;
    }

    // Check for duplicates in the rest of the list
    node *current = lst->head;
    while (current != NULL && current->nextpointer != NULL) {
        if (strcmp(name, current->nextpointer->name) == 0) {
            // Skill already exists, increment counter and return
            current->nextpointer->counter++;
            return;
        }
        current = current->nextpointer;
    }

    // If the skill does not exist, create a new node and insert it into the list
    node *new = malloc(sizeof(node));
    if (new == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    new->name = malloc(strlen(name) + 1);
    if (new->name == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(new);
        return;
    }

    strcpy(new->name, name);
    new->counter = 1;
    new->nextpointer = lst->head;  // Make the new node the new head
    lst->head = new;
} */

void skill_list_insert(struct skills_list_instance_t *lst, const char *name) {
    if (name == NULL || lst == NULL) {
        return;
    }

    // Check if the skill already exists
    node *current = lst->head;
    while (current != NULL) {
        if (strcmp(name, current->name) == 0) {
            // Skill already exists, increment counter and return
            current->counter++;
            return;
        }
        current = current->nextpointer;
    }

    // If the skill does not exist, create a new node
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    new_node->name = malloc(strlen(name) + 1);
    if (new_node->name == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(new_node);
        return;
    }

    strcpy(new_node->name, name);
    new_node->counter = 1;

    // Insert the new node in alphabetical order
    if (lst->head == NULL || strcmp(name, lst->head->name) < 0) {
        new_node->nextpointer = lst->head;
        lst->head = new_node;
    } else {
        node *prev = NULL;
        current = lst->head;

        while (current != NULL && strcmp(name, current->name) > 0) {
            prev = current;
            current = current->nextpointer;
        }

        new_node->nextpointer = current;
        prev->nextpointer = new_node;
    }
}


// Function to remove a skill 
void remove_skill(skills_list *list, const char *name)
{
   if (list == NULL || name == NULL) {
        // Handle invalid input
        return;
    }

    node *current = list->head;
    node *prev = NULL;

    // Traverse the list to find the node with the specified skill name
    while (current != NULL) 
    {
        if (strcmp(current->name, name) == 0) {
            // Found the node with the specified skill name
            if (prev == NULL) {
                // Node to be removed is the head of the list
                list->head = current->nextpointer;
            } else {
                // Node to be removed is not the head of the list
                prev->nextpointer = current->nextpointer;
            }

            // Free the memory occupied by the removed node
            free(current);

            // Exit the function after removing the skill
            return;
        }
}

}

// PURPOSE Frees the memory allocated by lst
void skill_list_destroy(skills_list *lst)
{
    /*node *n = lst->head;
    while (n != NULL)
    {
        node *killed = n;
        n = n->nextpointer;
        free(killed);
    }
    free(lst);*/ 
    node *current = lst->head;
    while (current != NULL) {
        node *temp = current;
        current = current->nextpointer;
        free(temp->name);  // Free the memory for the skill name
        free(temp);        // Free the memory for the node
    }
    lst->head = NULL;
    free(lst);
}

// PURPOSE; PRINT HEAD POINTER AND 
void list_print(skills_list *lst, FILE *out)
{
    lst->head = get_skill_at_index(lst, 0);
    node *n = lst->head;
    for (int i = 0; i < skill_list_length(lst); i++)
    {
        if (i == 0)
        {
        fprintf(out, "    Skills: %s ", n->name); 
        }
        else
        {
            fprintf(out, "            %s ", n->name);
        }
        if (n->counter > 1)
        {
            for(int i= 0; i < n->counter-1; i++)
             fprintf(out, "*");
        }
        fprintf(out, "\n");
        n = n->nextpointer; 
    }
      
}






