/* Thread Creation is a light operation in comparison to forking a process. The thread creation time is in the order of microseconds, 
while the process creation time is in the order of milliseconds. This is because threads share the same memory space and resources, 
while processes have their own memory space and resources. Therefore, creating a thread is much faster than creating a process.

Main thread is the thread that starts executing when a program is run. So every program has atleast one thread. Entry Point: main() in c++.
It is the initial thread of execution and is responsible for creating other threads if needed. Program ends when main thread ends.
thread t(task) : creates a new thread that executes the function task. The main thread continues to execute concurrently with the new 
thread, allowing for parallel execution of tasks. The main thread can also wait for the new thread to finish using t.join() or detach it 
using t.detach().

t.join(): Prevents main thread from exiting early. If the main thread finishes execution before the new thread, the program will terminate
 and the new thread will be stopped abruptly.

Real World Analogy : Process is like a company. Threads are workers. Main thread is like first employee (founder) and new threads are
additional employees.
*/

#include<iostream>
#include<thread>
#include<unistd.h>
using namespace std;

void task(){
    cout<<"Hello World\n";
}

int main(){
    for(int i=0;i<10;i++){
        timespec start,end;
        clock_gettime(CLOCK_MONOTONIC,&start);
        thread t(task);
        clock_gettime(CLOCK_MONOTONIC,&end);
        t.join();

        long seconds = end.tv_sec-start.tv_sec;
        long nanoseconds = end.tv_nsec-start.tv_nsec;

        cout<<seconds*(1e+9)+nanoseconds<<"\n";
    }
    return 0;
}

