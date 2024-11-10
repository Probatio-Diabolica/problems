#include"includes.hpp"

class Solution {
public:

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

    ListNode* mergeKLists(std::vector<ListNode*>& lists) 
    {

        if(lists.size()==0) return nullptr;
        ListNode* mainNode=lists[0];
        for(size_t i=0;i<lists.size();i++) 
        {
            mainNode=mergeTwoLists(lists[i],mainNode);
        }
        return mainNode;
    }
};

int main()
{
    std::vector<std::vector<int>> a={{}};
    std::cout<<a.size();
}