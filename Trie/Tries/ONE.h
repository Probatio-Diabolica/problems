#pragma once
#include<string>
using std::string;

struct Node
{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
    Node* get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node)
    {
        links[ch - 'a'] = node;
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }

};

class Trie {
public:
    Trie() {
        m_node = new Node();
    }

    void insert(string word) {
        Node* node = m_node;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word) {
        Node* node = m_node;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                //if here , then it mens letter does not exists 
                return false;
            }
            node = node->get(word[i]);
        }
        //return true is this word exists, else false if only occurances are there
        return node->isEnd();
    }

    bool startsWith(string word) {
        Node* node = m_node;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return true;
    }

private:
    Node* m_node;
};
