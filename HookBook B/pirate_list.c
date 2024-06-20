/* KEMI OMONIYI ato22 PSET 3 10/20/2023 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pirate_list.h"
#define INITIAL_CAPACITY (25)
#define RESIZE_FACTOR (2)

/**
 * Type of a list of pirates, as an opaque struct.
 */
typedef struct  pirate_list_instance_t{
    size_t length;
    size_t capacity;
    int (*comp)(const void *, const void *);
    pirate **array;
} pirate_list;

// PURPOSE: Allocate memory for a new pirate_list and return a pointer to it.
pirate_list *list_create(int (*comp)(const void *, const void *))
{
    pirate_list *lst = malloc(sizeof(pirate_list));
    lst->capacity = INITIAL_CAPACITY;
    lst->array = malloc(lst->capacity * sizeof(pirate*));
    lst->length = 0;
    lst->comp = comp;
    // account for  
    

    return lst;
    
}

//  PURPOSE: return the index of pirate
size_t list_index_of(pirate_list *pirates, pirate *p)
{
    if (pirates == NULL || p == NULL) {
        fprintf(stderr, "Error: NULL pointer passed to list_index_of.\n"); 
        return INITIAL_CAPACITY;
    }
    for (int i = 0; i<pirates->length; i++)
    {
        // Compare the current pirate with the target pirate use strcmp pirate[i] ->name

        // If the comparison is equal to 0, the pirates are considered equal and return the index where found
        if (strcmp(pirate_name(p),pirate_name(pirates->array[i])) == 0 )
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
        //size_t new_capacity = pirates->capacity * sizeof(pirate *);
        pirates->array = realloc(pirates->array, sizeof(pirate*) * pirates->capacity);
        fprintf(stderr, "Contract to %zu\n", pirates->capacity);
    }
}

pirate *list_insert(pirate_list *pirates, pirate *p, size_t idx)
{
    if (list_index_of(pirates, p) != list_length(pirates))
        {
            return p;
        }
   
    list_expand_if_necessary(pirates);
    
    if (idx > pirates->length)
    {
        fprintf(stderr, "Error: Invalid index for insertion.\n");
        return NULL;
    }

    
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
        pirates->length--;
        list_contract_if_necessary(pirates);
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
//PURPOSE: HELPER FUNCTION FOR QUICKSORTS WORKS TO HELP DIVIDE THE ARRAY/LIST ITERATING THROUGH
size_t partition(pirate_list *pirates, size_t i, size_t j)
{
    pirate *pivot =  list_access(pirates, i);
    size_t left = i;
    size_t right = j - 1;
    // Continue partitioning until the left pointer crosses the right pointer.
    while (left < right)
    {

        while (left <= right && pirates->comp(list_access(pirates,left), pivot) <= 0)
        {
            left++;
        }

        while (left <= right && pirates->comp(list_access(pirates, right), pivot) > 0 )
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
    return left - 1;
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
    
   // DOLUTION: quicksort(pirates, 0, pirates->length);
   quicksort(pirates, 0, list_length(pirates));
}

//PURPOSE: pirate compare by name 
int name_compare(const void *a, const void *b)
{
    pirate *x = (pirate *)a;
    pirate *y = (pirate *)b;
    if (a == NULL|| b == NULL)
    {
        return 1;
    }
    else 
    {
        return strcmp(pirate_name(x),pirate_name(y));
    }
    
}
// PURPOSE COMPARE VESSELS 
int vessel_compare(const void *a, const void *b)
{
    
    const pirate *v1 = (const pirate *)a;
    const pirate *v2 = (const pirate *)b;

    if (a == NULL && b == NULL ) 
    {
        return 0;
    }
    else if (pirate_vessel(v1) == NULL && pirate_vessel(v2) == NULL)
    {
        return 0;
    }
    else if (pirate_vessel(v1) != NULL && pirate_vessel(v2) == NULL)
    {
        return -1;

    } 
    else if (pirate_vessel(v1) == NULL && pirate_vessel(v2) != NULL )
    {

        // second one comes before the first one 
       
        return 1;
    }
 
    int ret = strcmp(pirate_vessel(v1),pirate_vessel(v2));
    return ret;
    
    
} 


int treasure_compare(const void *a, const void *b)
{
    const pirate *t1 = (const pirate *)a;
    const pirate *t2 = (const pirate *)b;
    if (a == NULL && b == NULL)
    {
        exit (1);
    } 
    else if (pirate_treasure(t1) == pirate_treasure(t2))
    {
        return 0;
    }
    else if (pirate_treasure(t1) < pirate_treasure(t2))
    {
        return 1;
    }
    else 
    {
        return -1;
    }
    
}


   

size_t list_length(pirate_list *pirates)
{
    if (pirates == NULL) {
        fprintf(stderr, "Error: Null pointer passed to list_length\n");
        return 0;
    }
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