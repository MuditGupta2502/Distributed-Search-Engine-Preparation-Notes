/* Zombie Process : It is a process that has completed its execution but still has an entry in the process table. This occurs when a child
 process finishes execution, but the parent process has not yet called wait() to read the child's exit status. The child process becomes a
  "zombie" because it is no longer running, but it still occupies a slot in the process table until the parent process retrieves its exit 
  status.

*/

#include<iostream>
#include<unistd.h>
#include<sys/wait.h>    // for wait() functions
using namespace std;

int main(){
    for(int i=0;i<5;i++){
        pid_t pid = fork();

        if(pid==0){
            cout<<"Child Process created"<<"\n";
            _exit(0);
        }
        else if(pid>0){
            wait(NULL); // wait for the child process to finish and retrieve its exit status
        }
        else{
            cout<<"Fork failed\n";
        }
    }
}