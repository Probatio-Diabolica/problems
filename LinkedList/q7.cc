#include<iostream>
#include<unordered_map>

struct Node
{
    int key,val;
    Node* next, * prev;
    Node(int k, int v):key(k),val(v)
    {
        next=nullptr;
        prev=nullptr;
    }
};

class LRUCache {
    int m_cap=0;
    std::unordered_map<int,Node*> m_map;
    Node* left,*right;
    //// left = LRU, right = most recent 

public:
    LRUCache(int capacity)  : m_cap(capacity)
    {
        left=new Node(0,0);
        right=new Node(0,0);

        left->next=right;
        right->prev=left;
    }
    
    void insert(Node* node)
    {
        Node * prev=right->prev, *nxt=right;
        prev->next=node;
        nxt->prev=node;
        node->next=nxt,node->prev=prev;
    }

    void remove(Node* node)
    {
        Node* prev=node->prev,*nxt=node->next;
        prev->next=nxt;
        nxt->prev=prev;
    }

    int get(int key) 
    {
        if(m_map.contains(key))
        {
            remove(m_map[key]);
            insert(m_map[key]);
            return m_map[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        if(m_map.contains(key)) remove(m_map[key]);
        m_map[key]=new Node(key,value);
        insert(m_map[key]);
        if(m_map.size() > m_cap)
        {
            int key=left->next->key;
            remove(left->next);
            m_map.erase(key);
        }
    }
};

int main()
{
    LRUCache l=LRUCache(2);
    l.put(12,90);
    std::cout<<l.get(12)<<"\n";
    l.put(23,45);
    l.put(7,2);
    std::cout<<l.get(12);
}