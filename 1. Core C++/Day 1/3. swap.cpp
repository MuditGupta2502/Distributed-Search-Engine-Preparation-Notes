#include<bits/stdc++.h>
using namespace std;

void swap_pointers(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap_reference(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int a = 1;
    int b = 2;

    swap_pointers(&a,&b);
    cout<<a<<" "<<b<<"\n";
    swap_reference(a,b);
    cout<<a<<" "<<b<<'\n';
}