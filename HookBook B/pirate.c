/* Author: Kemi Omoniyi ato22 PSET 3 10/16/2023
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pirate.h"
#include "pirate_list.h"
#include "skills_list.h"

struct pirate {
    char *name;
    char *rank;
    char *vessel;
    char *port;
    int treasure; 
    skills_list *skills;
    const pirate *captain;
}; 

pirate *pirate_create()
{
    pirate *p = malloc(sizeof(pirate));
    p->name = malloc(128 * sizeof(char));
    p->rank = NULL;
    p->vessel =  NULL;
    p->port =   NULL;
    p->captain =  NULL;
    p->treasure = 0; // create boolean if treasure exists in compare and print 
    return p;
} 


pirate *pirate_read(FILE *restrict input)
{
// create a new pirate and read a name 
    char line [128];
    pirate *p = pirate_create();
    
    //fgets(p->name, 128, input);
    if (fgets(line, 128, input) == NULL)
    {
        // Handle error or end of file
        pirate_destroy(p);
        return NULL;
    }
    pirate_set_name(p, line);
    p->name[strcspn(p->name, "\n")] = 0;
// then enter while loop and create logic for all 
    // want while loop to stop when i reach the end of my current pirate profile
   p->skills = skill_list_create();
    while (fgets(line, 128, input) != NULL && line[0] != '\n')
    {
        // use string strcmp(line, and newline line character  seperate if loop inside while loop 
        if (line[0] == 'r')
        {
            char *rank = line + 5;
            rank[strcspn(rank, "\n")] = 0;
            p->rank = malloc(sizeof(char) * 128);
            pirate_set_rank(p, rank);
        }
        else if (line[0] == 'v') 
        {   
            char *vessel = line + 7;
            vessel[strcspn(vessel, "\n")] = 0;
            p->vessel = malloc(sizeof(char) * 128);
            pirate_set_vessel(p, vessel);
        }
        else if (line[0] == 'p')
        {
            char *port = line + 5;
            port[strcspn(port, "\n")] = 0;
            p->port = malloc(sizeof(char) * 128);
            pirate_set_port(p, port);
        }
        else if (line[0] == 't') 
        {
            char *treasure = line + 9;
            p->treasure = atoi(treasure);
            pirate_set_treasure(p, p->treasure);
        }
        else if (line[0] == 's')
        {
            
            char *name = line + 6;
            size_t pos = strcspn(name, "\n");
            if (pos < strlen(name))
            {
                name[pos] = '\0';
            }
            skill_list_insert(p->skills, name);
            
        }
    }

    return p;
}

/**
 * Prints a pirate's profile to output in conformance with the output
 *  specification in the README.
 */
void pirate_print(const pirate *p, FILE *restrict output)
{
    if (p->name != NULL)
    {
        fprintf(output, "%s\n", p->name);
    }
    if (p->captain != NULL)
    {
        fprintf(output, "    Captain: %s (%s)\n", p->captain->name, p->captain->vessel);
    }  

    if (p->rank != NULL)
    {
        fprintf(output, "    Rank: %s\n", p->rank);
    }
    if (p->vessel != NULL)
    {
        fprintf(output, "    Vessel: %s\n", p->vessel);
    }
    if (p->port != NULL)
    {
        fprintf(output, "    Port: %s\n", p->port);
    }
    if (p->treasure != 0)
    {
        fprintf(output, "    Treasure: %d\n", p->treasure);
    }
    
    if (p->skills != NULL)
    {
        list_print(p->skills, output);
    }
}

// PURPOSE: return pirates name 
const char *pirate_name(const pirate *p)
{
    if (p == NULL)
    {
        return NULL;
    }
    return p->name;
}

// PURPOSE: set pirates name 
void pirate_set_name(pirate *p, const char *name)
{
    if (p == NULL || name == NULL)
    {
        return;
    }
     strcpy(p->name,name);
}

// PURPOSE: return pirate vessel 
const char *pirate_vessel(const pirate *p)
{
    if (p == NULL)
    {
        return NULL;
    }
    return p->vessel;
}

// PURPOSE: set vessel name
void pirate_set_vessel(pirate *p, const char *vessel)
{
    if (p == NULL || vessel == NULL)
    {
        return;
    }
    strcpy(p->vessel,vessel);
}

// PURPOSE: Returns the favorite port of call of the pirate.
const char *pirate_port(const pirate *p)
{
    if (p == NULL)
    {
        return NULL;
    }
    return p->port;
}

// PURPOSE: Sets the favorite port of call of a pirate.
void pirate_set_port(pirate *p, const char *port)
{
    if (p == NULL || port == NULL)
    {
        return;
    }
    strcpy(p->port, port);
}

// PURPOSE: Returns the rank of the pirate.
const char *pirate_rank(const pirate *p)
{
    if (p == NULL)
    {
        return NULL;
    }
    return p->rank;
}

//PURPOSE: Sets the rank of a pirate.
void pirate_set_rank(pirate *p, const char *rank)
{
    if (p == NULL || rank == NULL)
    {
        return;
    }
     strcpy(p->rank,rank);
}

// PURPOSE: Returns the treasure of the pirate.
unsigned int pirate_treasure(const pirate *p)
{
    if (p == NULL)
    {
        return 0;
    }
    return p->treasure;
}

// PURPOSE: Sets the treasure of a pirate.
void pirate_set_treasure(pirate *p, unsigned int treasure)
{
    if (p == NULL)
    {
        return;
    }
    p->treasure = treasure;
}

// Returns a pointer to the profile of the pirate's captain.
const pirate *pirate_captain(const pirate *p)
{
    if (p->captain != NULL)
    {
        return p->captain;
    }

    return NULL;
}

// PURPOSE: set captain of the pirate
void pirate_set_captain(pirate *p, const pirate *cpt)
{
    if (cpt != NULL)
    {
        p->captain = cpt;
    }
    else
    {
        p->captain = NULL;
    }
}
int pirate_compare(pirate *a, pirate *b)
{
    if (a == NULL|| b == NULL)
    {
        return 0;
    }
    else
    {
        return strcmp(a->name,b->name);
    }
    
}

// Returns a pointer to the list of skills of the pirate.
skills_list *pirate_skills(const pirate *p)
{
    if(p == NULL)
    {
        return NULL;
    }
    return p->skills;
}

// PURPOSE: Frees all memory associated with this pirate. This function claims ownership of p.
void pirate_destroy(pirate *p)
{
    if (p->name != NULL)
    {
        free(p->name);
    }
    if (p->rank != NULL)
    {
        free(p->rank);
    }
     if (p->port != NULL)
     {
         free(p->port);
     } 
     if (p->vessel != NULL)
     {
         free(p->vessel);
     } 
     if (p->skills != NULL)
     {
        skill_list_destroy(p->skills);
     }
    free(p);
}