#include<iostream>
#include<unordered_map>
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

std::ostream & operator<<(std::ostream& stream,Node* node)
{
    Node* temp=node;
    while(temp) 
    {
        stream<<temp->val<<" | ";
        temp=temp->next;
    }
    stream<<"\n";
    return stream;
}

Node* copyRandomList(Node* head) 
{
    std::unordered_map<Node*,Node*> map;
    map[nullptr]=nullptr;

    Node *iter=head;
    while(iter)
    {
        Node* temp=new Node(iter->val);
        map[iter]=temp;
        iter=iter->next;
    }
    iter=head;
    while(iter)
    {
        Node* temp= map[iter];
        temp->next=map[iter->next];
        temp->random=map[iter->random];
        iter=iter->next;
    }
    return map[head];
}

int main()
{
    
    Node* h1=new Node(0);
    Node* iter;
    iter=h1;

    for(int i =1;i<10;i++)
    {
        Node *temp=new Node(i);
        iter->next=temp;
        iter=iter->next;
    }
    std::cout<<h1;
    std::cout<<"\n COPY:: \n";
    std::cout<<copyRandomList(h1);
}