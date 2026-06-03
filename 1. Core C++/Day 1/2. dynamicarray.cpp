#include<bits/stdc++.h>
using namespace std;

class DynamicArray{
    private:
    int *data;
    int size;

    public:

    DynamicArray(int n){
        size = n;
        data = new int[n];
    }

    ~DynamicArray(){
        delete[] data;
    }

    int& at(int index){
        return data[index];
    }

    int getSize(){
        return size;
    }
};

int main(){
    DynamicArray arr(5);
    arr.at(0) = 10;
    arr.at(1) = 20;
    cout<<arr.at(0)<<" ";
    cout<<arr.getSize();
    return 0;
}