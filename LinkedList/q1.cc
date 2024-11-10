#include<iostream>


struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* Fw=nullptr,*Bw=nullptr,*C=head;
        while(C)
        {
            Fw=C->next;
            C->next=Bw;
            Bw=C;
            C=Fw;
        }

        return Bw;
    }
};

ListNode* reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    ListNode* newHead = reverseList(head->next);

    ListNode* front = head->next;
    front->next=head;

    head->next = NULL;  

    return newHead;
}

int main()
{
    ListNode *l= new ListNode(10);

    for(int i =0l;i<10;i++)
    {
        ListNode *temp=new ListNode(i+78,l);
        l=temp;
    }
    ListNode * temp=l;
    while(temp)
    {
            std::cout<<temp->val<<" | ";
            temp=temp->next;
    }
    std::cout<<"\n";

    // Solution sol=Solution();
    // l=sol.reverseList(l);
    l=reverseList(l);
    temp=l;
    while(temp)
    {
        std::cout<<temp->val<<" | ";
        temp=temp->next;
    }

    delete l;
}