/* KEMI OMONIYI 11/3/2023 PSET 4*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "gmap.h"
#include "entry.h"
#include "string_key.h"
#define MAX_ID  31
 void free_val (const void *key, void *value, void *lastarg)
    {
        free(value);
    }

int main(int argc, char* argv[]) 
{
    if (argc < 1)
    {
        exit(1);
    }
    gmap *your_map = gmap_create(duplicate, compare_keys, hash29, free);
    float final_score1 = 0.0;
    float final_score2 = 0.0;
    int battlefields = argc - 1;
    

    int *battlefield_values = malloc(sizeof(int) * battlefields);

    if (battlefield_values == NULL) 
    {
        exit(1);
    }
    int count = 0;
    for (int i = 1; i <= battlefields; i++)
    {
        battlefield_values[count] = atoi(argv[i]);
        count++;
    }
    
    // for loop to keep track stores 
    entry done = entry_read(stdin, MAX_ID, battlefields);
    if (done.id == NULL && done.distribution == NULL)
    {   entry_destroy(&done);
        gmap_destroy(your_map);
        exit(1);
    }
    while (done.id !=NULL && done.id[0] != '\0')
    {

        gmap_put(your_map, done.id, done.distribution);
        free(done.id);
        done = entry_read(stdin, MAX_ID, battlefields);
    }
   
    char *firstPlayer = malloc(sizeof(char) * MAX_ID);
    char *secondPlayer =  malloc(sizeof(char) * MAX_ID);
                
    while (scanf("%30s %30s", firstPlayer, secondPlayer) == 2)
    {
        final_score1 = 0.0;
        final_score2 = 0.0;
        if (!gmap_contains_key(your_map, firstPlayer) || !gmap_contains_key(your_map, secondPlayer))
        {
        
            exit(1);
        }
        int *distribution1 = (int *)gmap_get(your_map, firstPlayer);
        int *distribution2 = (int *)gmap_get(your_map, secondPlayer);
        if (distribution1 == NULL || distribution2 == NULL) 
        {
    
            fprintf(stderr, "Error: Player not found in the map.\n");
            exit(1);
    
        }
        for (int i = 0; i < battlefields; i++)
        {
   
            if (distribution1[i] > distribution2[i])
            {
                final_score1+=battlefield_values[i];
            }
            else if (distribution1[i] < distribution2[i])
            {
                final_score2+= battlefield_values[i];
            }
            else 
            {
                float result = battlefield_values[i] / 2.0;
                final_score1 += result;
                final_score2 += result;

            }
        }
        if (final_score1 > final_score2 || final_score1 == final_score2)
        {
            printf("%s %.1f - %s %.1f\n", firstPlayer, final_score1, secondPlayer, final_score2);
        }
        else if (final_score1 < final_score2)
        {
            printf("%s %.1f - %s %.1f\n", secondPlayer, final_score2, firstPlayer, final_score1);
        }
        
    }
   
    free(firstPlayer);
    free(secondPlayer);

    gmap_for_each(your_map, free_val, NULL);
    free(done.distribution);
    free(battlefield_values);
    entry_destroy(&done);
    // Clean up and destroy the map
    gmap_destroy(your_map);
    return 0;

}

