#include"includes.hpp"

// int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//     std::unordered_map<std::string,bool> visited;
//     visited[beginWord]=true;
//     std::string currWord;
//     std::queue<std::string> bfs;
//     bfs.push(beginWord);
//     int struggle=beginWord.length();
//     int turns=1;
//     ///Multi source BFS
//     while(!bfs.empty())
//     {
//         int s=bfs.size();
//         for(int i =0;i<s;i++)
//         {
//             currWord = bfs.front();
//             bfs.pop();
//             for(std::string & str : wordList)
//             {
//                 if(!visited[str])
//                 {
//                     int gap=0;
//                     for(int i=0;i<struggle;i++)
//                     {
                        
//                         if(currWord[i]!=str[i]) ++gap;
                        
//                     }
//                     if(gap<2) 
//                     {
//                         if(str==endWord) return turns+1;
//                         bfs.push(str);
//                         visited[str]=true;
//                     }
//                 }
//             }
//         }
//         ++turns;
//     }    
//     return  0;
// }

int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
{
    std::queue<std::pair<std::string,int>> q;
    q.push({beginWord,1});
    std::unordered_set<std::string> set(wordList.begin(),wordList.end());
    set.erase(beginWord);
    while(!q.empty())
    {
        std::string word = q.front().first;
        int steps=q.front().second;
        q.pop();
        if(word==endWord) return steps;
        for(int i=0;i<word.length();i++)
        {
            char original=word[i];
            for(char ch='a';ch<='z';ch++)
            {
                word[i]=ch;
                if(set.find(word)!=set.end())
                {
                    set.erase(word);
                    q.push({word,steps+1});
                }
            }
            word[i]=original;
        }
    }
    return 0;
}

int main()
{
    std::vector<std::string> list2={"a","b","c","d","e","f"};
    std::vector<std::string> list={"hot","dot","dog","lot","log","cog"};
    std::cout<<ladderLength("hit","cog",list)<<'\n';
    std::cout<<ladderLength("hot","cog",list)<<'\n';

    std::cout<<ladderLength("z","c",list2);

}