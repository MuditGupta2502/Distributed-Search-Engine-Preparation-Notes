/* Every time we run ./a.out we get a different process ID because each time we execute the program, the operating system assigns a 
unique process ID to that instance of the program. This is a fundamental aspect of how operating systems manage processes. 
Each process is given a distinct identifier (PID) to keep track of it, and this PID is typically assigned sequentially or based on 
available IDs in the system. Therefore, when you run the program multiple times, it will generate a new PID each time, 
resulting in different output for the process ID.

*/

#include<iostream>
#include<unistd.h>
using namespace std;

int main(){
    cout<<"Process ID is :"<<getpid()<<"\n";
    return 0;
}