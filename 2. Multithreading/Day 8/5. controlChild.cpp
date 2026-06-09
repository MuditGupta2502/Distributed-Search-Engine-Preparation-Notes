/* prevents explosion of processes : when a program calls fork() in a loop without any control, it can lead to an exponential growth of 
processes, which can overwhelm the system and lead to a crash.

_exit(0) : terminates the calling process immediately without performing any cleanup operations, such as flushing stdio buffers or 
calling functions registered with atexit(). Forceful termination can lead to resource leaks and other issues, as it does not allow the 
process to release resources properly.

exit(0) : performs cleanup operations before terminating the process, such as flushing stdio buffers and calling functions registered
with atexit(). It also takes an exit status code as an argument, which can be used to indicate the reason for termination to the parent 
process or the operating system.

*/

#include<iostream>
#include<unistd.h>
using namespace std;

int main(){
    pid_t process_id = fork();

    if(process_id==0){
        cout<<"This is a child process with pid : "<<getpid()<<"\n";
        _exit(0);
    }
    else if(process_id>0){
        cout<<"This is a parent process with pid : "<<getpid()<<"\n";
    }
    else{
        cout<<"Error\n";
    }
}