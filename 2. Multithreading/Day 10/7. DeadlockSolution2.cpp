/* Interview Solution : Use lock(a,b) : Deadlock avoidance internally. It breaks hold and wait condition of deadlock.

Thread A locks m1. Then it tries for m2. Suppose m2 is busy. Then it unlocks m1 and tries again.
Thread B locks m2. Then it tries for m1. Suppose m1 is busy. Then it unlocks m2 and tries again.

m.try_lock()

Eventually one thread wins and gets both locks. Other waits. No cycle. No deadlock.
*/



#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;

mutex m1;
mutex m2;

void work(){
    unique_lock<mutex>a(m1,defer_lock);
    unique_lock<mutex>b(m2,defer_lock);
    lock(a,b);
}

int main(){
    thread t1(work);
    thread t2(work);

    t1.join();
    t2.join();
}