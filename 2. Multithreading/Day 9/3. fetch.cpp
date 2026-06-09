#include<iostream>
#include<thread>
#include<vector>
#include<chrono>
using namespace std;

void fetch(int id){
    cout<<"Thread "<<id<<" fetching ....\n";
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout<<"Thread "<<id<<" done\n";
}

int main(){
    vector<thread>threads;

    for(int i=0;i<10;i++){
        threads.emplace_back(fetch,i);
    }

    for(auto &t:threads){
        t.join();
    }
}