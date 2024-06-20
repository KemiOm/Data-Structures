/**
 * Author: Kemi Omoniyi
 * ato22
 * 
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pirate_list.h"
#include "pirate.h"
#define INITIAL_CAPACITY 25
#define RESIZE_FACTOR 2


/**
 * Type of a list of pirates, as an opaque struct.
 */
typedef struct  pirate_list_instance_t{
    size_t length;
    size_t capacity;
    pirate **array;
} pirate_list;

// PURPOSE: Allocate memory for a new pirate_list and return a pointer to it.
pirate_list *list_create()
{
    pirate_list *lst = malloc(sizeof(pirate_list));
    lst->array = malloc(sizeof(pirate *) * INITIAL_CAPACITY);
    lst->capacity = INITIAL_CAPACITY;
    lst->length = 0;
    return lst;
}

//  PURPOSE: return the index of pirate
size_t list_index_of(pirate_list *pirates, pirate *p)
{
    for (int i = 0; i<pirates->length; i++)
    {
        // Compare the current pirate with the target pirate
        int comp = (pirate_compare(p, pirates->array[i]));
        // If the comparison is equal to 0, the pirates are considered equal and return the index where found
        if (comp == 0)
        {
            return i;
        }
    }
    return pirates->length;
}

// PURPOSE: Check if the actual number of pirates in the array is "too large"; if it is,
// increase the capacity of the array by a factor of RESIZE_FACTOR.
void list_expand_if_necessary(pirate_list *pirates)
{
    if(pirates->length >= pirates->capacity)
    {
        pirates->capacity *= RESIZE_FACTOR;
        //size_t new_capacity = pirates->capacity * sizeof(pirate *);
        pirates->array = realloc(pirates->array, sizeof(pirate*) * pirates->capacity);
        fprintf(stderr, "Expand to %zu\n", pirates->capacity);
    }
}

// PURPOSE: Check if the actual number of pirates in the array is "too small";
// if it is, decrease the capacity of the array by a factor of RESIZE_FACTOR.
void list_contract_if_necessary(pirate_list *pirates)
{
    if(pirates->capacity < pirates->length/4)
    {
        pirates->capacity /= RESIZE_FACTOR;
        size_t new_capacity = pirates->capacity * sizeof(pirate *);
        pirates->array = realloc(pirates->array, sizeof(pirate*) * pirates->capacity);
        fprintf(stderr, "Contract to %zu\n", new_capacity);
    }
}

pirate *list_insert(pirate_list *pirates, pirate *p, size_t idx)
{
    
    for(int j = 0; j< pirates->length; j++)
    {
        if(pirate_compare(list_access(pirates, j), p) == 0)
        {
            return NULL;
        }
    }

    list_expand_if_necessary(pirates);
    // shift elements to the right to make space for the new pirate
   for(int i = pirates->length; i > idx; i--)
    {
        pirates->array[i] = pirates->array[i - 1];
    }
    // Insert the new pirate at the specified index 
    pirates->array[idx] = p;
    pirates->length++;
    return p; 
 
}

// PURPOSE: to remove a specified pirate from the pirate list.
// If the pirate is found in the list, it is removed, and a pointer to the removed pirate is returned.
// If the pirate is not found, it returns NULL
pirate *list_remove(pirate_list *pirates, pirate *p)
{
    // Check if the target pirate is in the list
    if(list_index_of(pirates, p) != pirates->length)
    {
        // Create a temporary pointer to store the removed pirate.
        pirate *temporary = pirates->array[list_index_of(pirates, p)];
        // Shift elements to the left to fill the gap left by the removed pirate
        for(int i = list_index_of(pirates, p); i < pirates->length; i++)
        {
            pirates->array[i] = pirates->array[i + 1];
        }
        // Return a pointer to the removed pirate
        return temporary;

    }
    return NULL;
}


pirate *list_access(pirate_list *pirates, size_t idx)
{
    if(idx >= pirates->length)
    {
        return NULL;
    }

    return pirates->array[idx];
}

// PURPOSE: SEPERATES MY LIST USES MY PIVOT BASICALLY IMPLEMENTATION OF QUICKSORT
// BASED OFF OF MY LECTURE NOTES 
size_t partition(pirate_list *pirates, size_t i, size_t j)
{
    pirate *pivot =  list_access(pirates, i);
    size_t left = i;
    size_t right = j - 1;
    // Continue partitioning until the left pointer crosses the right pointer.
    while (left < right)
    {

        while (left <= right && pirate_compare(list_access(pirates,left), pivot) <= 0)
        {
            left++;
        }

        while (left <= right && pirate_compare(list_access(pirates, right), pivot) > 0 )
        {
            right--;
        }
        if ( left < right)
        {
            pirate *temp = pirates->array[left];
            pirates->array[left] = pirates->array[right];
            pirates->array[right] = temp;
        }
    }
    // Swap the pivot element with the element at left - 1
    pirates->array[i] = pirates->array[left - 1];
    pirates->array[left - 1] = pivot;
    return left-1;
}

// PURPOSE: HELPER AND RECURSIVE CALL 
void quicksort(pirate_list *pirates, size_t i, size_t j)
{
    if (j - i > 1)
    {
        size_t pivot_index = partition(pirates, i, j);
        quicksort(pirates, i, pivot_index);
        quicksort(pirates, pivot_index + 1, j);
    }
} 

// PURPOSE: SORT MY LIST OF NAMES 
void list_sort(pirate_list *pirates)
{
    quicksort(pirates, 0, pirates->length);
}
   

size_t list_length(pirate_list *pirates)
{
     return pirates->length;
}

// PURPOSE: FREE WHAT'S STORED AND THEN FREE ACTUALLY POINTER
void list_destroy(pirate_list *pirates)
{
   
    for(int i = 0; i < pirates->length; i++)
    {
        pirate_destroy(pirates->array[i]);
    }
    free(pirates->array);
    free(pirates);
}

