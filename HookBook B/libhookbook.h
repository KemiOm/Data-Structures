/* KEMI OMONIYI PSET 3 10/20/2023 */
#ifndef __LIBHOOKBOOK_H__
#define __LIBHOOKBOOK_H__
#include "pirate_list.h"  
#include "pirate.h"

/*Author: [Kemi Omoniyi]
*/
// PURPOSE: THIS FUNCTION IS MEANT TO HELP ME READ IN MY SPECIFC CAPTAIN FILE AND ACCORDINGLY ASSIGN THOSE VALUES 
// PARAMETERS: INPUT FILE AND A LIST OF PIRATES 
void captain_read(FILE *restrict input, pirate_list *pirates);
#endif