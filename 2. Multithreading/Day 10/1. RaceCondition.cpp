/* Concurrency : When multiple threads are accessing and modifying shared (same) data concurrently, it can lead to a race condition.

Race condition happens when multiple threads access and modify shared data at the same time, atleast one writes to it and there is no 
proper synchronization mechanism in place to control the access to the shared data. 
Race condition simply means that the outcome of a program depends on the timing and interleaving of threads, which can lead to 
unpredictable results.
Threads "race" to update memory first. Race bugs are nondeterministic : sometimes correct, sometimes broken.

counter++;
This operation is not atomic. It consists of three steps:
1. Read the value of counter from memory into a register.
2. Increment the value in the register.
3. Write the updated value back to memory.

If two threads execute counter++ at the same time, they can both read the same value of counter, increment it, and write it back, 
resulting in lost updates and incorrect results.
*/


#include<iostream>
#include<thread>
using namespace std;

int counter=0;

void task(){
    for(int i=0;i<100000;i++)
    counter++;
}

int main(){
    thread t1(task);
    thread t2(task);

    t1.join();
    t2.join();

    cout<<counter<<"\n";
}