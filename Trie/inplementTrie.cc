#include<iostream>
#include<vector>
using  std::vector,std::cout,std::string;

struct Node
{
    Node* links[26];
    bool end=false;

    bool contains(char ch)
    {
        return links[ch-'a'] !=NULL;
    }

    void putChar(char ch)
    {
        links[ch-'a']=new Node();
    }

    Node* getChar(char ch)
    {
        return links[ch-'a'];
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
class Trie {
private:
    Node* m_root; 
public:

    Trie() {
        m_root= new Node();
    }
    
    //O(N) N=> len of word
    void insert(string word) {
        Node* temp=m_root;
        for(int i=0;i<word.length();i++)
        {
            if(! temp->contains(word[i])) temp->putChar(word[i]); 
            //moves to the reference Node
            temp=temp->getChar(word[i]);
        }
        //sets end to be true
        temp->setEnd();
    }
    
    //O(N) len of word
    bool search(string word) {
        Node* temp=m_root;
        for(int i=0;i<word.length();i++)
        {
            if(!temp->contains(word[i])) return false;
            temp=temp->getChar(word[i]);
        }
        
        return temp->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* temp=m_root;
        for(int i=0;i<prefix.length();i++)
        {
            if(!temp->contains(prefix[i])) return false;
            temp=temp->getChar(prefix[i]);
        }

        return true;
    }
    ~Trie()
    {
        delete m_root;
        m_root=nullptr;
    }
};


int main()
{
    Trie* t=new Trie();
    t->insert("qas");
    cout<<"\n"<<t->startsWith("asc");
    cout<<"\n"<<t->search("qas");
    cout<<"\n"<<t->startsWith("q");
    delete t;
    t=nullptr; 
}