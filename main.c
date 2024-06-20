/*
Driver for Game of Life assignment in CPSC 223 Fall 2023

Author: Kemi Omoniyi
*/

#include "life.h"
#include "helpers.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// TO STUDENT: Do not change this definition!
#ifndef SIZE
#define SIZE 10
#endif
// End modification restriction

int main(int argc, char *argv[])
{
    // pass through command line arguments 
    int time_steps = atoi(argv[1]);
    char init[SIZE+1];
    strcpy(init, argv[2]);
    
   
    // static array 
    int current[SIZE];
    for(int i = 0; i < SIZE; i++){
        current[i] = argv[2][i] - '0';
    } 
     // TODO: Print the initial values held in the array
     print_initial(current, SIZE); 

    // create a next state  array  
    int next[SIZE];
    
    // apply the rules 
  
    for(int i = 0; i < time_steps; i++){
        
        for(int m = 0; m < SIZE; m++){
        // copy my current into my next 
        next[m] = current[m];
        }

        for(int k = 0; k < SIZE; k++){
            // CHECK IF STATE IS EVEN ALIVE 
            if (isAlive(current, k, SIZE)){
                // NEXT CHECK FOR LIVE NEIGHBORS
                // BUT NEED TO CHECK FOR EDGE CASES 
                if(k == SIZE-1 || k == 0)
                {
                    next[k] = current[k];
                }

                if(k+1 < SIZE-1 && current[k+1] == 0){
                     next[k+1] = 1;
                }
                 else if(k-1 >= 0 && current[k-1] == 0){
                    next[k-1] = 1;
                }

                if(shouldDie(current, k, SIZE)){
                // IF LIVE NEIGHBORS SET CURRENT TO ZERO 
                    next[k] = 0;
                }
               
                //printf("%d ", shouldDie(current, k, SIZE)); 
            }
            // if not alive no change 
            else{
                next[k] = next[k];
            }
        }
        // move on to next generation but print
        // print_generation(current, i+1, SIZE);
        // when do i copy my current into my next state 

        for(int s = 0; s < SIZE; s++){
            // copy next into current
            current[s] = next[s];
        }
        print_generation(current, i+1, SIZE);
    }

    return 0;
}