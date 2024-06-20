```markdown
# Author
Kemi Omoniyi
ato22

# Estimate of time to complete assignment
15 hours

# Actual time to complete assignment
| Date  | Time Started | Time Spent | Work completed                                                                                                        |
| :---: | -----------: | ---------: | :-------------------------------------------------------------------------------------------------------------------- |
| 10/3  |      10:48pm |       3:00 | read assignment, created necessary files -----|
| 10/4  |       9:00pm |       2:30 | make pirate.c and made pirate_list.c--|
| 10/5  |       8:00pm |       4:00 | troubleshooting segmentation faults---|
| 10/6  |      11:45am |       1:30 | Fixed seg faults---|
| 10/6  |      6:00pm  |       4:00 | finished debugging; program passes all public tests---|
|       |              |     17:00  | total time spent                  |

# Collaboration
I discussed my solution with: Fatima Aw and Jordan Miller 
# Discussion
My first mistake was tring to write my implementation in my header files. I blame this mostly on my forgetfulness and I fixed that and created my c files as soon as possible. 
When I initially created my pirate.c file I didn't encounter any errors it wouldnt' be until i did my driver file and tried to run my project where i would notice something wrong with my pirate_read function. I wasn't checked for null inputs and needed to be more specific when telling my program when to malloc memory. 
In pirate_print I was missing \n and had a weird indent because I had an extra space in the function. 
For pirate_compare I had to look up to strcmp format in my declaration I didn't label my parameters as pointers. 
In pirate_list.c I had more issues. My first major one is that intially I kept having segmentation faults because I wasn't setting the values of my capacity and length. 
For list_index_of I had an seg fault because I had a type in the return of my loop. I was returning 1 instead of i.
In my list_expand_if_necessary I had a seg error because I was expanding my list too much. A TA helped me realize that my intial if statement wherre I'm  making my comparison was wrong I had pirates->capacity >= pirates->length and I needed pirates->length >= pirates->capacity. 
Another seg error came from my list_insert where I wasn't checking if my pointer was null before inserting. 
I fixed my quick_sort I referred back to lecture when professor gave us an example of quicksort and fixed my types since we are working with a struct
Went through once everything officially worked and started accounting for cases, like if my command line argument has a null file or if I have too many command line arguements 
I created a funciton to handle if my pirate name is in uppercase letters so it doesn't disturb my order. 
My last issue was my quickSort being wrong turns out i+1 was really supposed to be i 

