#include<iostream>
#include<vector>
#define start 'a'

class Node
{
public:
    Node* links[26];
    bool end=false;

    void put(char ch)
    {
        links[ch-start]=new Node();
    }

    Node* get(char ch)
    {
        return links[ch-start];
    }

    bool contains(char ch)
    {
        return links[ch-start]!=NULL;
    }

    void setEnd()
    {
        end=true;
    }

    bool isEnd()
    {
        return end;
    }
    
};

class Trie
{
private:
    Node* m_root;
public:
    Trie()
    {
        m_root=new Node();
    }

    void insert(std::string & sweat)
    {
        Node * temp=m_root;
        for(int i =0 ; i<sweat.length();i++)
        {
            if(!temp->contains(sweat[i])) temp->put(sweat[i]);
            temp=temp->get(sweat[i]);
        }
        temp->setEnd();
    }

    bool checkIfPrefixExists(std::string& prefix)
    {
        Node* temp=m_root;
        bool flag = true;
        for(int i = 0; i < prefix.length();i++)
        {
            if(temp->contains(prefix[i]))
            {
                temp=temp->get(prefix[i]);
                flag=flag & temp->isEnd();
            }
            else return false;
        }

        return flag;
    }

};


std::string completeString(int n, std::vector<std::string> &a)
{
    Trie trie=Trie();

    for(std::string& st : a ) trie.insert(st);
    
    std::string longest="";

    for(std::string& word : a )
    {
        if(trie.checkIfPrefixExists(word))
        {
            if(word.length() > longest.length())
            {
                longest=word;
            }
            else if ((word.length() == longest.length()) &&  word < longest)
            {
                longest=word;
            }
        }
    }

    return (longest=="") ? "None" : longest;

}




int main()
{
    std::vector<std::string> vec={"n" ,"ni" ,"nin" ,"ninj" ,"ninja", "ninga"};
    std::cout<<completeString(0,vec);
}