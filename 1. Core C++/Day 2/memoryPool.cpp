#include<iostream>
#include<array>
#include<stdexcept>
using namespace std;

struct URLEntry{
    char URL[512];
    int status;
};

template<size_t N>
class Pool{
    union Slot{
        URLEntry obj;
        Slot *next;
    }
    array<Slot,N>buffer;
    Slot* head = nullptr;

    public:

    Pool(){
        for(auto i=0;i<N-1;i++){
            buffer[i].next=&buffer[i+1];
        }
        buffer[N-1].next=nullptr;
        head=&buffer[0];
    }

    URLEntry* alloc(){
        if(head==nullptr){
            throw :bad_alloc;
        }
        Slot *s = head;
        head=head->next;

        return new(&s->obj) URLEntry{};
    }

    void free(URLEntry *p){
        p->~URLEntry();
        Slot *s = reinterpret_cast(p);
        s->next = head;
        head=s;
    }

    
};

