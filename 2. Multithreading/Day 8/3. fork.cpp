#include<iostream>
#include<unistd.h>
using namespace std;

int main(){
    fork();
    fork();
    fork();
    cout<<"Hello World\n";


    return 0;
}
