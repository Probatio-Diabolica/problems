#include<iostream>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


std::ostream & operator<<(std::ostream& stream,ListNode* node)
{
    ListNode* temp=node;
    while(temp) 
    {
        stream<<temp->val<<" | ";
        temp=temp->next;
    }
    return stream;
}


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode *head=new ListNode();
    ListNode *iter=head;
    
    while(l1 and l2)
    {
        if(l1->val > l2->val)
        {
            iter->next=l2;
            l2=l2->next;
        }
        else
        {
            iter->next=l1;
            l1=l1->next;
        }
        iter=iter->next;   
    }
    if (l1) iter->next= l1;
    else if(l2) iter->next=l2;
    return head->next;
}

int main()
{
    ListNode *h1= new ListNode(2000);
    ListNode *h2= new ListNode(1000);
    for(int i =10;i>0;i--)
    {
        ListNode *temp=new ListNode(i*20,h1);
        h1=temp;
        ListNode *temp2=new ListNode(i*30,h2);
        h2=temp2;
    }
    std::cout<<h1<<"\n"<<h2<<"\n";

    ListNode *it=mergeTwoLists(h1,h2);
    std::cout<<"sorted and merged\n"<<it;

    delete h1;
    delete h2;
}