/* Mutex is mutual exclusion. Only one thread enters critical section at a time. Critical section is piece of code touching shared data.
Lock is a mechanism to control access to shared data by multiple threads. It allows only one thread to access the shared data at a time,
ensuring that the critical section is executed by only one thread, preventing race conditions and ensuring data integrity.
Unlock is used to release the lock after the critical section is executed, allowing other threads to acquire the lock and access the 
shared data.
*/

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

//counter is a global variable and hence is shared variable (memory) between multiple threads.
int counter=0;
mutex m;

void increment(){
    for(int i=0;i<100000;i++){
        m.lock();
        counter++;
        m.unlock();
    }
}

int main(){
    thread t1(increment);
    thread t2(increment);

    t1.join();
    t2.join();
    cout<<counter<<"\n";
}