#include<iostream>
#include<vector>
#pragma region Base

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* fillUpEnd(ListNode* h1)
{
    ListNode* iter=h1;
    for(int i =10;i>0;i--)
    {
        ListNode *temp=new ListNode(i*2);
        iter->next=temp;
        iter=iter->next;

    }
    return h1;
}

ListNode* fillUpHead(ListNode* h1)
{
    for(int i =10;i>0;i--)
    {
        ListNode *temp=new ListNode(i*20,h1);
        h1=temp;
    }
    return h1;
}

std::ostream & operator<<(std::ostream& stream,ListNode* node)
{
    ListNode* temp=node;
    while(temp) 
    {
        stream<<temp->val<<" | ";
        temp=temp->next;
    }
    stream<<"\n";
    return stream;
}

#pragma endregion now
