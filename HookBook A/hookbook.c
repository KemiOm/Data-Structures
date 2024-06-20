// Author: Kemi Omoniyi ato22
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pirate.h"
#include "pirate_list.h"

int main(int argc, char *argv[]) {
    // Check for the correct number of command-line arguments
    if (argc < 2) 
    {
        printf("Wrong amount of command-line arguments");
        return 1;
    }
   
    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) 
    {
        printf( "Can't open the file");
        return 1;
    }

    pirate_list *pirates = list_create();

    // Read pirates from the input file and add them to the list
    
    while (!feof(inputFile)) 
    {
        pirate *p = pirate_read(inputFile);
        // Insert the pirate into the list
        if (p != NULL)
        {
            
           if(list_insert(pirates, p, list_length(pirates)) == NULL)
            {
                pirate_destroy(p);
            } 
           
        }
    }
    fclose(inputFile);

    list_sort(pirates);

    // Print the sorted list of pirates
    for (size_t i = 0; i < list_length(pirates); i++) 
    {
        pirate_print(list_access(pirates, i), stdout);
    }

    list_destroy(pirates);

    return 0;
}
