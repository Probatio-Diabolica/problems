#include "includes.hpp"
#include <stdlib.h>
struct Node
{
    int data;
    Node* link;
};

struct Stack
{
    Node* head;
};
typedef struct Stack st;
void push(st* __st,int value)
{
    if(__st->head == nullptr)
    {
        Node* newNode= (Node*) malloc(sizeof(Node));
        newNode->data = value;
        newNode->link=nullptr;
        __st->head=newNode;
        cout<<"pushed above\n";
        return;
    }
    Node* temp;
    temp=__st->head;
    while(temp->link)
    {
        temp=temp->link;
    }
    Node* newNode= (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->link=nullptr;
    temp->link=newNode;
    cout<<"pushed\n";
}

void pop(st* __st)
{
    if(__st->head==nullptr)
    {
        cout<<"stack underflow\n";
        return;
    }    
    else if(__st->head->link==nullptr)
    {
        __st->head=nullptr;
        return;
    }
    Node* temp,*prev;
    prev=__st->head;
    temp=__st->head->link;

    while(temp->link)
    {
        temp=temp->link;
        prev=prev->link;
    }
    
    std::cout<<"deleted "<<temp->data<<"\n";
    prev->link=nullptr;

}

std::ostream& operator<<( std::ostream& stream,st* __st)
{
    if(__st->head==nullptr)
    {
        stream<<"Empty stack\n";
        return stream;
    }

    Node* temp;
    temp=__st->head;
    while(temp)
    {
        stream<< temp->data<<" ,";
        temp=temp->link;
    }
    return stream;
}

int main()
{
    st __st=st();
    for(int i=0;i<12;i++)
    {
        push(&__st,i*6 + 9);
    }
    cout<<&__st<<"\n";
    for(int i=0;i<12;i++)
    {
        pop(&__st);
    }
    cout<<&__st;
}
