/* True Parallelism: In true parallelism, multiple threads can run simultaneously on different CPU cores. This allows for better 
performance and faster execution of tasks, especially for CPU-bound operations. Each thread can execute independently without waiting for 
others to finish, leading to improved efficiency and responsiveness in applications.

move semantics : It is a feature in C++ that allows the resources of an object to be transferred from one object to another without
copying.

emplace_back() : It constructs an object in place at the end of the vector, eliminating the need for a temporary object and a move or copy
operation. example: vector<thread> threads;
threads.emplace_back(task,i);
*/

#include<iostream>
#include<thread>
#include<vector>
#include<chrono>
using namespace std;

void task(int data){
    this_thread::sleep_for(chrono::milliseconds(1000));
}

int main(){
    vector<thread>threads;

    auto start = chrono::steady_clock::now();
    
    for(int i=0;i<10;i++){
        thread t(task,i);
        threads.push_back(move(t)); // move the thread object into the vector to avoid copying
    }

    for(auto& t : threads){
        t.join();
    }

    auto end = chrono::steady_clock::now();

    auto time_difference = chrono::duration_cast<chrono::milliseconds>(end-start);

    cout<<time_difference.count()<<"\n";
}