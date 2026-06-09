/* Process Synchronization in operating system is a mechanism which coordinates the execution of multiple processes or threads access shared
resources.

Producer Consumer problem is a classic synchronization challenge where a producer generates data and places it into a fixed sized buffer
while consumer process removes data from that same buffer. The key issue is ensuring the producer waits when the buffer is full (overflow)
and consumer waits when buffer is empty (underflow).
*/

#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;

void producer(){

}

void consumer(){

}

int main(){
    thread t1(producer);
    thread t2(producer);
    thread t3(producer);
    thread t4(producer);

    thread c1(consumer);
    thread c2(consumer);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}