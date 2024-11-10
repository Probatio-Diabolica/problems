#include"includes.hpp"

class Solution {
    // int m_st[50000],top=-1;
public:
    // void reorderList(ListNode* head) {
    //     top=-1;
    //     ListNode* iter=head;
    //     while(iter)
    //     {
    //         m_st[++top]=iter->val;
    //         iter=iter->next;
    //     }
    //     iter=head;
    //     int index=-1,count=-1;
    //     while(iter)
    //     {
    //         iter->val= ((++count)&1) ? m_st[top--]:m_st[++index];
    //         iter=iter->next;
    //     }
    // }

    ListNode *reverse(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *temp = head;
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (temp != nullptr)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;
        return head;
    }

    void reorderList(ListNode* head)
    {
        ListNode* slow = head, *fast = head, *first_half=head;
        fast = fast->next;
        while(fast&&fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second_half = reverse(slow->next);
        slow->next = nullptr;
        while(second_half){
            ListNode* temp = first_half->next, *tem=second_half->next;
            first_half->next = second_half;
            second_half->next = temp;
            first_half = temp;
            second_half =tem;
        }
    }
};


int main()
{
    ListNode* h1=new ListNode(5);
    for(int i =10;i>0;--i)
    {
        ListNode *temp=new ListNode(i,h1);
        h1=temp;
    }

    std::cout<<h1;
    Solution sol=Solution();
    sol.reorderList(h1);
    std::cout<<h1;
}