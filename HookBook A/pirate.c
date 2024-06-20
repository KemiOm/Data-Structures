/* Author: Kemi Omoniyi ato22 
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pirate.h"
typedef struct pirate_instance_t{
    char *name;
} pirate;


pirate *pirate_create()
{
    pirate *plst = malloc(sizeof(pirate));
    return plst;
}


pirate *pirate_read(FILE *input)
{
    // pointer creating an instance of pirate with the size needed 

    if (input == NULL)
    {
        return NULL;
    }

    char line[128];
    if (fgets(line, 128, input) != NULL)
    {
        line[strcspn(line, "\n")] = '\0';

        char *name = malloc(sizeof(char) * 128);
        strcpy(name, line);
        if (strlen(name) > 2)
        {
            pirate *new = pirate_create();
            new->name = name;
            return new;
        }
        free(name);
    }

    return NULL;
}

 //PURPOSE: Prints a pirate's profile to output in conformance with the output
void pirate_print(const pirate *p, FILE *output)
{
    fprintf(stdout, "%s\n", p->name);
}

// PURPOSE: returns name of pirate
const char *pirate_name(const pirate *p)
{
    return p->name;
}

// PURPOSE: set name of pirate
void pirate_set_name(pirate *p, const char *name)
{
     strcpy(p->name,name);
}


//PURPOSE: Compares two pirates, returning a negative number, zero, or a positive 
//number as pirate a "comes before", is equal to, or "comes after" pirate b.
int pirate_compare(pirate *a, pirate *b)
{
  
    return strcmp(a->name,b->name);
    
}


// PURPOSE: Frees all memory associated with this pirate. This function claims ownership
void pirate_destroy(pirate *p)
{
    if (p->name != NULL)
    {
    free(p->name);
    } 
    free(p);
}

