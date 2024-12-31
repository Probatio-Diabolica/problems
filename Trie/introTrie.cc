#include<iostream>

struct Node
{
    Node* links[26];

    bool flag=false;

    bool containsKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }

    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }

    Node* get(char ch)
    {
        return links[ch-'a'];
    }

    void setEnd()
    {
        flag=true;
    }

    bool isEnd()
    {
        return flag;
    }
    ~Node()
    {
        if(links) delete[] links;
    }
}; 

class Trie
{
public:
    Trie()
    {
        m_root= new Node();
    }



private:
    Node* m_root;

};