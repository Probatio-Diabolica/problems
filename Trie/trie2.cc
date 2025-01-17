#include <iostream> 
using namespace std;




struct Node
{
    Node* link[26];
    int count=0;
    int ends=0;

    void putChar(char ch)
    {
        link[ch-'a']=new Node();
    }
    Node* getChar(char ch)
    {
        return link[ch-'a'];
    }
    bool contains(char ch)
    {
        return link[ch-'a']!=NULL;
    }

    void increaseEnd()
    {
        ++ends;
    }
    void delEnd()
    {
        --ends;
    } 
    void increaseCount()
    {
        ++count;
    }
    void delCount()
    {
        --count;
    }

};

class Trie{

    public:

    Trie()
    {
        m_root= new Node();
    }

    void insert(const string &word)
    {
        Node * temp=m_root;
        for(int i=0;i<word.length();i++)
        {
            if(!temp->contains(word[i])) 
            {
                temp->putChar(word[i]);
            }
            
            temp=temp->getChar(word[i]);
            temp->increaseCount();
        }
        temp->increaseEnd();

    }

    int countWordsEqualTo(const string &word)
    {
        Node* temp=m_root;
        for(int i=0;i<word.length();i++)
        {
            if(temp->contains(word[i])) temp=temp->getChar(word[i]);
            else return 0;
        }

        return temp->ends;
    }

    int countWordsStartingWith(const string &word)
    {
        Node* temp=m_root;
        for(int i=0;i<word.length();i++)
        {
            if(temp->contains(word[i])) temp=temp->getChar(word[i]);
            else return 0;
        }
        return temp->count;

    }

    void erase(const string &word)
    {
        Node* temp=m_root;
        for(int i=0;i<word.length();i++)
        {
            if(temp->contains(word[i]))
            {
                temp=temp->getChar(word[i]);
                temp->delCount();
            } 
            else return;

        }
        temp->delEnd();

    }
    ~Trie()
    {
        delete m_root;
        m_root=nullptr;

    }
private:
    Node* m_root;
};

int main()
{
    Trie* t=new Trie();
    t->insert("qas");
    cout<<"\n"<<t->countWordsEqualTo("asc");
    cout<<"\n"<<t->countWordsStartingWith("qas");
    cout<<"\n"<<t->countWordsEqualTo("q");
    delete t;
    t=nullptr; 
}