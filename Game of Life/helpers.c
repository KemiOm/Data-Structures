/*
Implementations of helper functions for Game of Life assignment for CPSC 223 Fall 2023.
// #Author: Alan Weide 

TO STUDENT: You may add to this file, but do not change anything that is already here!
Modified by: Kemi Omoniyi on September 18
Changelog: [what you added to this file]
*/

#include "helpers.h"
#include <stdio.h>

void print_initial(int field[], size_t size)
{
    printf("%-16s[ ", "Initial Values");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", field[i]);
    }
    printf("]\n");
}

void print_generation(int field[], unsigned int gen, size_t size)
{
    printf("Step %-10d [ ", gen);
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", field[i]);
    }
    printf("]\n");
}