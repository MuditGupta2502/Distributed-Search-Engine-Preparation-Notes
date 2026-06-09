#include<iostream>
#include<thread>
#include<mutex>
#include<queue>
#include<condition_variable>
using namespace std;

queue<int>q;
mutex m;
condition_variable cv;
bool done=false;

void producer(){
    for(int i=0;i<5;i++){
        unique_lock<mutex>lock(m);
        q.push(i);
        lock.unlock();
        cv.notify_one();
        cout<<"Producer produced item "<<i<<"\n";
    }
    {
        unique_lock<mutex>lock(m);
        done=true;
    }
    cv.notify_all();
}

void consumer(){
    while(true){
    unique_lock<mutex>lock(m);
    while(q.empty() and done==false){
        cv.wait(lock);
    }

    if(q.empty() and done){
        return ;
    }

    if(q.empty()==false){
        auto item = q.front();
        q.pop();

        cout<<"Consumer consumed item "<<item<<"\n";
    }
    }  
}

int main(){
    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();
    return 0;
}


/*Week 2 : thread pool ; producer consumer problem ;  h2o molecule problem*/