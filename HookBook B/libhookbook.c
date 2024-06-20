/* KEMI OMONIYI PSET 3 10/20/2023 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pirate.h"
#include "pirate_list.h"

void captain_read(FILE *restrict input, pirate_list *pirates)
{
    char line[128];

    // Read the first line
    while (fgets(line, sizeof(line), input) != NULL && line[0] != '\n')
    {
        // Remove newline character if present
        line[strcspn(line, "\n")] = 0;

        for (int i = 0; i < list_length(pirates); i++)
        {
            if (strcmp(line, pirate_name(list_access(pirates, i))) == 0)
            {
                // Match found, set the captain
                if(fgets(line, sizeof(line), input) != NULL) // Read the next line
                {
                line[strcspn(line, "\n")] = 0;  // Remove newline character if present

                    for (int j = 0; j < list_length(pirates); j++)
                    {
                        if (strcmp(line, pirate_name(list_access(pirates, j))) == 0)
                        {
                            pirate_set_captain(list_access(pirates, i), list_access(pirates, j));
                            // Add a print statement here to check if the captain is being set correctly
                        }
                    }
                }   
            }
        }
    }
} 



