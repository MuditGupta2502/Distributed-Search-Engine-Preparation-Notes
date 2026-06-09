// Always lock in same order

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

mutex m1;
mutex m2;

void functionA(){
    m1.lock();
    cout<<"Thread A locks m1\n";
    m1.unlock();

    this_thread::sleep_for(chrono::milliseconds(2000));

    m2.lock();
    cout<<"Thread A locks m2\n";
    m2.unlock();
}

void functionB(){
    m1.lock();
    cout<<"Thread B locks m1\n";
    m1.unlock();

    this_thread::sleep_for(chrono::milliseconds(2000));

    m2.lock();
    cout<<"Thread B locks m2\n";
    m2.unlock();
}

int main(){
    thread t1(functionA);
    thread t2(functionB);

    t1.join();
    t2.join();
}