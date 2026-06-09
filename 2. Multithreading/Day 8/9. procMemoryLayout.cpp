/* /proc is a virtual (not real) filesystem in Linux. Created by kernel. Shows live process+system info.
ls /proc    --> we will see process ids.
/proc/<pid>/maps --> shows memory layout of a process. this includes code segment, heap,stack,shared libraries and memory mapped files.

Address range : memory region from start to end
Permissions : r for readable ; w for write ; x for executable and p for private
*/

#include<iostream>
#include<thread>
#include<unistd.h>
using namespace std;

void task(){
    sleep(100);
}

int main(){
    cout<<"Process ID is "<<getpid()<<"\n";
    thread t(task);
    sleep(100);
    return 0;
}
