#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

mutex m;

void check_conditional(bool need_lock){
    unique_lock<mutex>lock(m,defer_lock);

    if(need_lock){
        lock.lock();
        cout<<"This thread locks\n";
    }

    else{
        cout<<"This thread does not locks\n";
    }
}

int main(){
    thread t1(check_conditional,true);
    thread t2(check_conditional,false);
    return 0;
}