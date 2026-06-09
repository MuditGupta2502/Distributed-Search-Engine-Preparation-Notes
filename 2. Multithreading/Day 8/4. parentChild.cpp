/* fork() is a system call in Unix-like operating systems that creates a new process by duplicating the calling process. 
The new process created by fork() is called the child process, and the original process is called the parent process. 
After a fork() call, both the parent and child processes will execute the same code following the fork() call,
 but they will have different process IDs (PIDs) and may execute different code based on the return value of fork().

 child process will have pid 0 and parent process will have pid > 0. If fork() returns a negative value, it indicates that the fork failed.
*/

#include<iostream>
#include<unistd.h>
using namespace std;

int main(){
    pid_t pid = fork();
    
    if(pid==0){
        cout<<"I am a child process with PID: "<<getpid()<<"\n";
    }
    else if(pid>0){
        cout<<"I am a parent process with child process PID: "<<pid<<"\n";
    }
    else{
        cout<<"Fork failed\n";    // pid<0 indicates fork failure
    }
    return 0;
}