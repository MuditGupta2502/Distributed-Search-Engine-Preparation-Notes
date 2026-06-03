#include<bits/stdc++.h>
using namespace std;

void reverse(int *arr, int n){
    int *left = arr;
    int *right = arr+n-1;

    while(left<right){
        int temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }
}

int main(){
    int arr[]={1,2,3,4,5};
    reverse(arr,5);

    for(auto &x:arr)
    cout<<x<<" ";

    return 0;
}