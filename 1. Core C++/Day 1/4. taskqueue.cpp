#include<bits/stdc++.h>
using namespace std;

void downloadPage(){
    cout<<"Download Page";
}

void parseHTML(){
    cout<<"Parse HTML";
}

void buildIndex(){
    cout<<"Build Index";
}

int main(){
    void (*taskqueue[3])();
    taskqueue[0] = downloadPage;
    taskqueue[1] = parseHTML;
    taskqueue[2] = buildIndex;

    for(int i=0;i<3;i++){
        taskqueue[i]();
        cout<<"\n";
    }
    return 0;
}