#include "life.h"
// Author: Kemi Omoniyi ato22
bool isAlive(int field[], size_t i, size_t size) 
{
    // if the value at this specific index is 1 than its alive 
    if(field[i] == 1){
        // return true
        return true;
    }
    else {
    // other case of its' not being 1 is 0 which would indicate thats it's dead 
     return false;
    }
}

bool shouldDie(int field[], size_t i, size_t size) 
{
    /* first look at edge cases where the program won't have 2 neighbors when field[i-1] == -1 and when field[i+1] == size 
    program should return false */ 

    // check if it has neighbors 
    if(i == 0 || i == size - 1)
    {
        return false;
    }
    // next check if the neighbors are both alive 
    else if(field[i-1] == 1 && field[i+1] == 1){
        return true;
    }
    else{
    // for the last case where field[i] has two neighbors but they both aren't alive
        return false;
    }

}