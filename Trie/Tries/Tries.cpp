#include <iostream>
#include "ONE.h"
int main()
{
    Trie t = Trie();
    t.insert("apple");
    std::cout << t.startsWith("app")<<" :: "<< t.startsWith("pp")<<"  :: "<<t.search("apple");
    std::cin.get();
}

