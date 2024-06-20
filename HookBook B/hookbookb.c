/* KEMI OMONIYI PSET 3 10/20/2023 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pirate.h"
#include "pirate_list.h"
#include "skills_list.h"
#include "libhookbook.h"
/**
 * This will be the file where your main function is going to be. Your main function must:
 * Take three command-line arguments: the path to a file containing the pirates' profiles, the path to a file containing pirate/captain pairs, and the sort order.
 * Open the profiles file and read from it the list of pirate profiles, appearing as sepcified below, storing them in a pirate_list*
 * Open the captains file and read from it the list of pirate/captain pairs, appearing as specified below
 * Sort the list in the order defined by the third command-line argument
 * Print the sorted list to stdout, conforming to the format described below in Output Format
 * Release all resources (files, memory, etc.)
*/
int main(int argc, char *argv[])
{
     if (argc > 4)
    {
        fprintf(stderr, "Too many arguements\n" );
        return 1;
    }
    // not enough arguments 
     if (argc < 3)
    {
        fprintf(stderr, "not enough arguements\n" );
        return 1;
    }
    int counter = 0; 
    for (int i = 0; i < argc; i++)
    {
        if (strstr(argv[i], ".txt") != NULL )
        {
            counter ++;
         }
        if (counter > 2)
        {
            fprintf(stderr, "Too many files!");
            exit(1);
        }
    }
    FILE *pfile;  // Initialize to NULL to handle failure cases
    FILE *cfile;
    bool found_flag = false;
    pirate_list *pirates;
    for (int i = 1; i < argc; i++)
    {
        char *first_arg = argv[i];
        // first index then profiles is i +1 and captain is i +2 
        if (first_arg[0] == '-'  && i == 1)
        {
            pfile = fopen(argv[i + 1], "r");
            cfile = fopen(argv[i + 2], "r");
            
        }
        if (argc == 3) 
        {
            pfile = fopen(argv[1], "r");
            cfile = fopen(argv[2], "r");
            
        }
      
        // second index then profiles is i -1 and captain is i + 1
        else if (first_arg[0] == '-' && i == 2)
        {
            pfile = fopen(argv[i - 1], "r");
            cfile = fopen(argv[i + 1], "r");
        }
        // third index then profile  is i -2 and captain is i -1 
        else if (first_arg[0] == '-' && i == 3)
        {
            pfile = fopen(argv[i - 2], "r");
            cfile = fopen(argv[i - 1], "r");
        }
        else if (first_arg[0] != '-' && argc == 2)
        {
            pfile = fopen(argv[1], "r");
            cfile = fopen(argv[2], "r");
        }

    }
   
    // Check if the file is successfully opened
    if (pfile == NULL && cfile == NULL) 
    {
        fprintf(stderr, "Error: Unable to open file Exiting.\n");
        exit(1);
    }
   
   for (int i = 0; i < argc; i++) 
    {
        if ((strcmp(argv[i], "-n") == 0) || argc == 3) 
        {
            pirates = list_create(name_compare);
            found_flag = true;
        }
        if ((strcmp(argv[i], "-v") == 0)) 
        {
            pirates = list_create(vessel_compare);
            found_flag = true;
        } 
        if ((strcmp(argv[i], "-t") == 0)) 
        {
            pirates = list_create(treasure_compare);
            found_flag = true;
        }
        
    }
    if (!found_flag)
    {
         fprintf(stderr,"Invalid sort flag\n");
         exit (1);
    }
    
    while (!feof(pfile)) 
    {
        pirate *p = pirate_read(pfile);
        // Insert the pirate into the list
        if (p != NULL)
        {
           
           list_insert(pirates, p, list_length(pirates)); 
           
        }
    }

   while (!feof(cfile)) 
    {
        // fix
         captain_read(cfile, pirates);
        // Insert the pirate into the list
    } 
    
    list_sort(pirates);

    // Print the sorted list of pirates
    for (size_t i = 0; i < list_length(pirates); i++) 
    {
        pirate_print(list_access(pirates, i), stdout);
         
        
    }

    list_destroy(pirates);
        fclose(pfile);
        fclose(cfile);  
    return 0;
} 
