/* KEMI OMONIYI 11/3/2023 PSET 4*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "gmap.h"
#define GMAP_INITIAL_CAPACITY 29
void embiggen (gmap *m, size_t new_capacity);
typedef struct _node
{
    const void *key;
    void *value;
    struct _node *next;

} node;
 typedef struct _gmap 
{
    node ** table;
    size_t capacity;
    size_t size;
    size_t (*hash)(const void *);
    int (*compare)(const void *, const void *);
    void *(*copy)(const void *);
    void (*free)(void *);
}gmap;


char *gmap_error = "Error";
// Purpose: Creates an empty map that uses the given hash function.
gmap *gmap_create(void *(*cp)(const void *), int (*comp)(const void *, const void *), size_t (*h)(const void *), void (*f)(void *))
{
    if (cp == NULL || comp == NULL || h == NULL || f == NULL)
    {
        return NULL;
    }
    gmap *mymap = (gmap *)malloc(sizeof(gmap));
    
     if (mymap != NULL)
    {
        // remember the functions used to manipulate the keys
        mymap->copy = cp;
        mymap->compare = comp;
        mymap->hash = h;
        mymap->free = f;

        // initialize the table
        mymap->table = (node **)calloc(GMAP_INITIAL_CAPACITY, sizeof(node *));
        if (!mymap->table)
        {
            free(mymap);
            return NULL;
        }
        // if initialize capacity one-conditional statement
        mymap->capacity = (mymap->table != NULL) ? GMAP_INITIAL_CAPACITY : 0;
        mymap->size = 0;
    }
    return mymap;
}

//Returns the number of (key, value) pairs in the given map. Behavior
size_t gmap_size(const gmap *m)
{
    if (m == NULL)
    {
        return 0;
    }
    return m->size;
}

/**
 * Adds a copy of the given key with value to this map.  If the key is
 * already present then the old value is replaced and returned.  The
 * map copies the key, so the caller retains ownership of the original
 * key and may modify it or destroy it without affecting the map.  The
 * map copies the pointer to the value, but the caller retains
 * ownership of the value. Behavior is undefined if either m or key is
 * NULL.
 */
void *gmap_put(gmap *m, const void *key, void *value)
{
    if ( m == NULL || key == NULL)
    {
        gmap_error ="Memory allocation error";
        return NULL;
    }
    // now i need my resize logic 
    if (m->size == m->capacity)
    {
        size_t new_capacity = m->capacity * 2;
        // Resize the hashtable
        embiggen(m, new_capacity);
    }
    // before adding to my hashtable I need to hash it 
   
    size_t index = (m->hash)(key) % m->capacity;

    // look for existing I need to iterate through my linked list and look 
    node *current = m->table[index]; 
    // create another node for when I need to update the next thing in my list 
    node *previous = NULL;
    void *old = NULL;
    while (current != NULL)
    {
       if (m->compare (current->key, key) == 0)
       {
        //key present replace and return 
            old = current->value;
            //current->value = value;
            current->value = value;
            // return the old MAKE CHANGE 
            return old;
       }
        previous = current;
        current = current->next;
    }

    // else I need to create a new node 
    node *new = malloc(sizeof(node));
    if (new == NULL)
    {
        gmap_error = "Memory allocation error with new ndoe";
        return NULL;
    }
    // assign the value/key passed in to the new node that I'm adding make sure that I'm using a copy of the key 
    new->key = m->copy(key);
    new->value = value;
    new->next = NULL;
    // add to the linkedlist of our hashtable
    if (previous == NULL) 
    {
    // First node 
        m->table[index] = new;
    } 
    else 
    {
    // Add to the end of the linked list
        previous->next = new;
    }
    m->size++;
    return NULL;
}

/**
 * Removes the given key and its associated value from the given map if
 * the key is present.  The return value is NULL and there is no effect
 * on the map if the key is not present.  The copy of the key held by
 * the map is destroyed.  It is the caller's responsibility to free the
 * returned value if necessary. Behavior is undefined if either m or key
 * is NULL.
 */
void *gmap_remove(gmap *m, const void *key)
{
    if(m == NULL || key == NULL)
    {
        return NULL;
    }
    size_t index = (m->hash)(key) % m->capacity;

    node *current = m->table[index];
    node *prev = NULL;

    while (current != NULL)
    {
        if (m->compare(current->key, key) == 0)
        {
            // Key found, remove the node from the linked list
            if (prev == NULL)
            {
                // First node in the bucket
                m->table[index] = current->next;
            }
            else
            {
                // Node in the middle or end of the linked list
                prev->next = current->next;
            }    
        
            // Save the value to return later
            void *removed_value = current->value;
            // Free the key and the node
            m->free((void *)(current->key));
            free(current);

            // Update the size of the map
            m->size--;

            return removed_value;
        }
        prev = current;
        current = current->next;

    }
    // Key not found, return NULL
    return NULL;
}


// Determines if the given key is present in this map. Behavior is undefined if either m or key is NULL.
bool gmap_contains_key(const gmap *m, const void *key)
{
    if (m == NULL || key == NULL)
    {
        // Invalid parameters, behavior is undefined
        return false;
    }

    size_t index = (m->hash)(key) % m->capacity;

    node *current = m->table[index];

    while (current != NULL)
    {
        if (m->compare(current->key, key) == 0)
        {
            // Key found in the map
            return true;
        }
        current = current->next;
    }

    // Key not found
    return false;
}
/**
 * Returns the value associated with the given key in this map.
 * If the key is not present in this map then the returned value is
 * NULL.  The pointer returned is the original pointer passed to gmap_put,
 * and it remains the responsibility of whatever called gmap_put to
 * release the value it points to (no ownership transfer results from
 * gmap_get). Behavior is undefined is either m or key is NULL.
 */
void *gmap_get(gmap *m, const void *key)
{
    if (m == NULL || key == NULL)
    {
        return NULL;
    }
    size_t index = (m->hash)(key) % m->capacity;

    node *current = m->table[index];

    while (current != NULL)
    {
        if (m->compare(current->key, key) == 0)
        {
            // Key found in the map, return the associated value
            return current->value;
        }
        current = current->next;
    }

    // Key not found
    return NULL;
}

/**
 * Calls the given function for each (key, value) pair in this map, passing
 * the extra argument (arg) as well. Behavior is undefined if either m or f
 * is NULL.
 */
void gmap_for_each(gmap *m, void (*f)(const void *, void *, void *), void *arg)
{
    if (m == NULL || f == NULL)
    {
        // Handle invalid input
        return;
    }

    // Iterate through each bucket in the table
    for (size_t i = 0; i < m->capacity; ++i)
    {
        // Iterate through the linked list in each bucket
        node *current = m->table[i];
        while (current != NULL)
        {
            // Call the provided function for each (key, value) pair
            f(current->key, current->value, arg);

            // Move to the next node in the linked list
            current = current->next;
        }
    }
}

/**
 * Returns an array containing pointers to all of the keys in the
 * given map.  The return value is NULL if there was an error
 * allocating the array.  The map retains ownership of the keys, and
 * the pointers to them are only valid as long until they are removed
 * from the map, or until the map is destroyed, whichever comes first.
 * It is the caller's responsibility to destroy the returned array if
 * it is non-NULL. Behavior is undefined is m is NULL.
 */
const void **gmap_keys(gmap *m)
{

    if (m == NULL)
    {
        // Invalid parameter, behavior is undefined
        return NULL;
    }

    // Allocate memory for an array of pointers to keys
    const void **keys = malloc(sizeof(const void *) * m->size);
    if (keys == NULL)
    {
        return NULL;
    }
    size_t keysIndex = 0;
    for (int i = 0; i < m->capacity; i++)
    {
        node *current = m->table[i];
        while (current != NULL)
        {
            // Add the key to the array
            keys[keysIndex++] = current->key;

            // Move to the next node in the linked list
            current = current->next;
        }
    }

    return keys;
    }

//Destroys the given map.  There is no effect if the given pointer is NULL.
void gmap_destroy(gmap *m)
{
    if (m == NULL)
    {
        // Nothing to destroy
        return;
    }

    // Iterate through each bucket in the table
    for (size_t i = 0; i < m->capacity; ++i)
    {
        // Iterate through the linked list in each bucket
        node *current = m->table[i];
        while (current != NULL)
        {
            // Free the key and the node
            m->free((void *)(current->key));
            node *next = current->next;
            free(current);
            current = next;
        }
    }

    // Free the table
    free(m->table);

    // Free the map structure
    free(m);
}
// function that expands/ shrinks my hashtable to account for the required time complexity 

void embiggen (gmap *m, size_t new_capacity)
{
     node **new_table = (node **)calloc(new_capacity, sizeof(node *));
    if (!new_table)
    {
        gmap_error = "Memory allocation error during resize";
    }

    // Rehash all elements to the new table
    for (size_t i = 0; i < m->capacity; ++i)
    {
        node *current = m->table[i];
        while (current != NULL)
        {
            size_t new_index = (m->hash)(current->key) % new_capacity;
            node *next = current->next;
            current->next = new_table[new_index];
            new_table[new_index] = current;
            current = next;
        }
    }

    // Free the old table
    free(m->table);

    // Update the table and capacity in the map
    m->table = new_table;
    m->capacity = new_capacity;
}
// create a gmap_destroy key