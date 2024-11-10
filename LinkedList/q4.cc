#include"includes.hpp"

void fastpointer(ListNode* head)
{
    ListNode* fast;
    fast=head->next;
    std::cout<<"fast pointer \n";
    while(fast && fast -> next)  
    {
        std::cout<<fast->val <<" | ";
        fast = fast ->next->next;
    }
    std::cout<<"\n";
}
ListNode* removeNthFromEndOP(ListNode* head, int n)
{
    ListNode* dum=new ListNode(0,head);
    head=dum;

    ListNode* left=head,*right=head;
    int gap=0;
    while(right && right->next)
    {
        right=right->next;
        if(gap==n)  left=left->next;
        else ++gap; 
    }
    left->next=left->next->next;

    return head->next;
} 

ListNode* removeNthFromEndBF(ListNode* head, int n) 
{
    int count=1;
    ListNode* iter=head->next;
    while(iter )
    {
        ++count;
        iter=iter->next->next-> next;
    }
    int pos=count-(n);
    iter=head;
    if(count==n) 
    {
        head=head->next;
        return head;
    }
    else{
        while(pos>1)
        {
            iter=iter->next;
            --pos;
        }
        iter->next=iter->next->next;
    }
    return head;
}

int main()
{
    ListNode* h1=new ListNode(0);
    ListNode* iter;
    iter=h1;
    for(int i =1;i<20;i++)
    {
        ListNode *temp=new ListNode(i);
        iter->next=temp;
        iter=iter->next;
    }
    std::cout<<h1;
    std::cout<<removeNthFromEndOP(h1,4);
    // fastpointer(h1);
    delete h1;
    delete iter;
}