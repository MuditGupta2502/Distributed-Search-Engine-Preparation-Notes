/* A thread is a lightweight unit of execution inside a process. A process can have multiple threads, and all threads within a process 
share the same memory space and resources. Every thread has its own stack and registers but they share the same heap and global variables.

A thread must be joined (t.join()) or detached (t.detach()). If not then internally joinable(t.joinable()) will be true and when the 
thread object goes out of scope, it will call std::terminate() which will end the program abruptly. So joinable() means when thread exists
but not joined or detached by programmer. So we should always join or detach the thread to avoid this situation.

detach() : It allows the thread to **run independently from the main thread**. Once detached, the thread will continue to execute even if 
the main thread finishes execution. Detached threads cannot be joined, and their resources are automatically released when they finish
execution.

join() : It blocks the calling thread until the thread on which join() is called has finished executing. This allows for synchronization 
between threads, ensuring that the main thread **waits** for the completion of the joined thread before proceeding.

Always prefer join() over detach() because it allows for better control and synchronization(safe) of threads. Detaching a thread can lead to
issues such as resource leaks and undefined behavior if the detached thread accesses resources that have been released by the main thread.
In detach thread may use memory which is already destroyed by main thread.
Joining a thread ensures that the main thread waits for the completion of the joined thread, allowing for proper cleanup of resources and
avoiding potential issues with detached threads. 

Thread Lifecycle : New --> Runnable --> Running --> Blocked --> Terminated.
New : When a thread is created, it is in the new state. It has been allocated resources but has not yet started executing.

Runnable : When the thread is ready to run but is waiting for the CPU to be allocated to it, it is in the runnable state. T
The thread scheduler will determine when the thread gets to run.

Running : When the thread is executing its task. Actively using CPU time.

Blocked : Sleep ; I/O operations ; waiting for a lock or condition variable. Not using CPU time.

Terminated : When the thread has completed its execution or has been terminated by another thread, it is in the terminated state.

Lambda Captures : Capture by value is safe because it creates a copy of the variable for the thread to use, ensuring that the thread has 
its own independent copy of the variable. Capture by reference can lead to issues if the original variable goes out of scope or is modified
by another thread while the thread is still using it, which can result in undefined behavior (thread crashes if variable gets destroyed). 
Therefore, it is generally recommended to capture by value when using lambda functions in multithreaded environments.
*/

// Spawn 10 threads each fetching a url segment in sequence.

//sequential execution of threads. main thread will wait for each thread to finish before starting next one.


#include<iostream>
#include<thread>
#include<unistd.h>
#include<chrono>
using namespace std;

void task(int data){
    this_thread::sleep_for(chrono::milliseconds(1000));
}

int main(){
    auto start = chrono::steady_clock::now() ;\

    for(int i=0;i<10;i++){
        thread t(task,i);
        t.join();   
    }
    auto end = chrono::steady_clock::now();

    auto time_difference = chrono::duration_cast<chrono::milliseconds>(end-start);

    cout<<time_difference.count()<<"\n";
}