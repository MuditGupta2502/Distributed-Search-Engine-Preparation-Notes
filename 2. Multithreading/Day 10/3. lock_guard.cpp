/* Why lock / unlock is not recommended? --> If we forget to unlock the mutex after locking it, it can lead to a deadlock situation where 
other threads are waiting indefinitely for the lock to be released. This can cause the program to become unresponsive and may require a 
manual intervention to terminate it.

Solution : lock_guard is a C++ standard library class that provides a convenient and exception-safe way to manage mutex locks. It 
automatically acquires the lock when it is created and releases the lock when it goes out of scope. This ensures that the mutex is always 
properly released, even if an exception is thrown within the critical section.
*/

#include<iostream>
#include<mutex>
#include<thread>

using namespace std;

int counter=0;
mutex m;

void increment(){
    for(int i=0;i<100000;i++){
        lock_guard<mutex>guard(m);
        counter++;
    }
}

int main(){
    thread t1(increment);
    thread t2(increment);

    t1.join();
    t2.join();

    cout<<counter<<"\n";
}