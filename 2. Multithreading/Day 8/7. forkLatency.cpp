#include<iostream>
#include<unistd.h>
#include<vector>
#include<sys/wait.h>
using namespace std;

int main(){
    vector<double>forkLatecies;
    timespec start,end;
    for(int i=0;i<10;i++){
        clock_gettime(CLOCK_MONOTONIC,&start);
        pid_t pid = fork();

        if(pid==0){
            _exit(0);
        }
        else if(pid>0){
            wait(NULL);
        }
        else{
            cout<<"Fork failed\n";
        }
        clock_gettime(CLOCK_MONOTONIC,&end);

        long seconds = end.tv_sec - start.tv_sec;
        long nanoseconds = end.tv_nsec - start.tv_nsec;

        cout<<nanoseconds<<"\n";

        double total_time = seconds*1e+9+nanoseconds;
        //cout<<total_time<<"\n";

        forkLatecies.push_back(total_time);
    }

    double average_time = 0;

    for(int i=0;i<forkLatecies.size();i++){
        average_time += forkLatecies[i];
    }

    cout<<"Average time is : "<<average_time/forkLatecies.size()<<"\n";
}