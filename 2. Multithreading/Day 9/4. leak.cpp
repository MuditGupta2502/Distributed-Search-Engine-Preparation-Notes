/* Error : terminate called without an active exception
Thread
Aborted (core dumped)

Why? --> Thread starts. main() reaches end. t goes out of scope. Destructor of std::thread is called.
Now inside the destructor of thread, since thread is not joined or detached by programmer , it is still joinable() --> terminate. 
Hence program will crash.

*/
#include<iostream>
#include<thread>
using namespace std;

void task(){
    cout<<"Thread\n";
}

int main(){
    thread t(task);
    cout<<t.joinable()<<"\n";  // If 1 gets printed then thread is running/finished but not joined/detached by programmer
}