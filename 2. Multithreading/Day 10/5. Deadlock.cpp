#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;

mutex m1;
mutex m2;

void functionA(){
    cout<<"Thread 1 is trying to lock m1\n";
    unique_lock<mutex>lock1(m1);
    cout<<"Thread 1 locked m1\n";

    this_thread::sleep_for(chrono::milliseconds(2000));

    cout<<"Thread 1 is trying to lock m2\n";
    unique_lock<mutex>lock2(m2);
    cout<<"Thread 1 locked m2\n";

}

void functionB(){
    cout<<"Thread 2 is trying to lock m2\n";
    unique_lock<mutex>lock1(m2);
    cout<<"Thread 2 locked m2\n";

    this_thread::sleep_for(chrono::milliseconds(2000));

    cout<<"Thread 2 is trying to lock m1\n";
    unique_lock<mutex>lock2(m1);
    cout<<"Thread 2 locked m1\n";
}

int main(){
    thread t1(functionA);
    thread t2(functionB);

    t1.join();
    t2.join();
}