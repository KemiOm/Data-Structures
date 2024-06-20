/* KEMI OMONIYI PSET 5 11/13/2023 */
# Author
Kemi Omoniyi
ato22

# Estimate of time to complete assignment
15 hours

# Actual time to complete assignment
| Date  | Time Started | Time Spent | Work completed |
| :---: | -----------: | ---------: | 
| 11/13 |      10:30 am|       2:00 | read assignment,  did implementation for Station.cpp----|
| 11/14 |      11:30 pm |       1:30| tried some implementation for LinkedList.cpp----|
| 11/15 |       7:40pm |       4:30 | make linked.list and tried to troubleshoot remove --|
| 11/16 |       8:00pm |       2:00 | troubleshooting linked.list--|
                       |       7:30| TOTAL HOURS SPENT --|


# Collaboration
I discussed my solution with: Kris Aziabor, Jordan Miller
# Discussion
I spent a long time reading over the file and making sure I understood the implementatio of the
program in C++; I haven't had much practice on my own creating this in C++ , so that to me a 
minute to understand. It took me a office hour session to undestand how to copy the constructor and overload the assignment operator. From there I was able to build most things include my remove function. I then compiled everything and I was having a segmentation fault in my reomve function and my print wasn't working either. I had to go back and reformat my print I had an endl part in my station.cpp. I fixed my remove the real problem was hidden in my insert I wasn't doing it properly and referring to currPos and not this->head. 
This fixed all of my issues and lastly I had was failing case 10 because I wasn't resetting length and my head pointer.