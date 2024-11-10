#include"includes.hpp"


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    int carry=0,sum= (l1->val) + (l2->val) ;
    if(sum>9) 
    {
        carry=1;
        sum%=10;
    }
    ListNode * newNode = new ListNode(sum);
    ListNode* iter=newNode;
    ListNode* a =l1->next,*b = l2->next;
    while(a or b)
    {
        sum= ((a) ? (a->val) : 0 )+ ((b) ? (b->val): 0) + carry;
        carry= (sum>9) ? 1 : 0;
        ListNode* temp=new ListNode(sum%10);
        iter->next=temp;
        iter=iter->next;

        if(a) a=a->next;
        if(b) b=b->next;
    }
    
    if(carry==1) 
    {
        ListNode* temp=new ListNode(1);
        iter->next=temp;
    }
    return newNode;
}


int main()
{
    ListNode* node1=new ListNode(9);
    ListNode* node2=new ListNode(9),*iter1=node1,*iter2=node2;
    for(int i=1;i<9;i++)
    {
        ListNode* temp1=new ListNode(9);
        ListNode* temp2=new ListNode(9);
        
        iter1->next=temp1;
        if(i<5) iter2->next=temp2;

        iter1=iter1->next;
        if(i<5) iter2=iter2->next;
    }

    std::cout<<node1 <<"[node gap]\n"<<node2;
    std::cout<<addTwoNumbers(node1,node2);

    delete node1,delete node2;
}