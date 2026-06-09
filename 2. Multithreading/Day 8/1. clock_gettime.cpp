// time  = seconds + nanoseconds
// keeps number scalable and accurate : seconds --> large scale number , nanaoseconds --> small scale and accuarte number for precision

// Cache operations are in nanoseconds. like L1 and L2 cache access time is in nanoseconds. 
// so we can use clock_gettime() to measure the time taken by cache operations and other operations in nanoseconds..

// clock_getime() : control, precision, OS-Level, system call.

/* clock_monotonic : it is a clock that cannot be set and represents monotonic time since some unspecified starting point. It is not 
affected by changes in the system time (e.g., if the user changes the system clock or if there are adjustments for daylight saving time).
This makes it ideal for measuring elapsed time intervals, as it provides a consistent and reliable measure of time that is not 
influenced by external factors.   */

/* struct timespec {
    time_t tv_sec;  // seconds
    long   tv_nsec; // nanoseconds
} */


#include<iostream>
#include<ctime>
using namespace std;

int main(){
    timespec start,end;

    clock_gettime(CLOCK_MONOTONIC,&start);

    for(int i=0;i<10000000;i++);

    clock_gettime(CLOCK_MONOTONIC,&end);


    long seconds = end.tv_sec - start.tv_sec;
    long nanoseconds = end.tv_nsec - start.tv_nsec;

    cout<<"Seconds: "<<seconds<<endl;
    cout<<"Nanoseconds: "<<nanoseconds<<endl;

    double elapsed = seconds + nanoseconds*1e-9; // convert nanoseconds to seconds and add to seconds

    cout<<"Elapsed time: "<<elapsed<<" seconds"<<endl;

    return 0;
}