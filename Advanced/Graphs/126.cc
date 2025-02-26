#include"includes.hpp"
////unoptimized
// vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
// {
//     std::unordered_set<std::string> set(wordList.begin(),wordList.end());
//     std::queue<std::vector<std::string>> q;
//     q.push({beginWord});
//     std::vector<std::string> used;
//     used.push_back(beginWord);
//     int level=0;
//     std::vector<std::vector<std::string>> sol;
//     while(!q.empty())
//     {
//         std::vector<std::string> vec = q.front();
//         q.pop();
//         if(vec.size()>level)
//         {
//             ++level;
//             for(auto it:used)
//             {
//                 set.erase(it);
//             }
//             used.clear();
//         }

//         std::string word = vec.back();
//         if(word==endWord)
//         {
//             if(sol.size()==0) sol.push_back(vec); 
//             else if(sol[0].size()==vec.size()) sol.push_back(vec);
//         }
//         for(int i=0;i<word.size();i++)
//         {
//             char original=word[i];
//             for(char c='a';c<='z';c++)
//             {
//                 word[i]=c;
//                 if(set.count(word)>0)
//                 {
//                     vec.push_back(word);
//                     q.push(vec);
//                     used.push_back(word);
//                     vec.pop_back();
//                 }
//             }
//             word[i]=original;
//         }
//     }
//     return sol;
// }

void dfs(std::string& currWord,std::string& beginWord,vector<string>& sequence,vector<vector<string>>& ans,unordered_map<std::string,int> &map)
{
    if(currWord==beginWord) 
    {
        reverse(sequence.begin(),sequence.end());
        ans.push_back(sequence);
        reverse(sequence.begin(),sequence.end());
        return;
    }
    int steps=map[currWord];
    int size=beginWord.length();
    for(int i =0;i<size;i++)
    {
        char ori = currWord[i];
        for(char c='a';c<='z';c++)
        {
            currWord[i]=c;
            if(map.count(currWord) and map[currWord]+1 == steps)
            {
                sequence.push_back(currWord);
                dfs(currWord,beginWord,sequence,ans,map);
                sequence.pop_back();
            }
        }
        currWord[i]=ori;
    }

}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
{   
    vector<vector<string>> ans;
    unordered_set<string> set(wordList.begin(),wordList.end());
    std::queue<std::string> q;
    unordered_map<std::string,int> map;
    map[beginWord]=1;
    q.push(beginWord);
    int size = beginWord.size();
    set.erase(beginWord);

    while(!q.empty())
    {
        std::string word = q.front();
        q.pop();
        int steps = map[word];
        if(word==endWord) break;
        for(int i =0;i<size;i++)
        {
            char ori = word[i];
            for(char c='a';c<='z';c++)
            {
                word[i]=c;
                if(set.count(word))
                {
                    q.push(word);
                    set.erase(word);
                    map[word]=steps+1;
                }
            }
            word[i]=ori;
        }
    }

    if(map.contains(endWord)){
        std::vector<std::string> seq;
        seq.push_back(endWord);
        dfs(endWord,beginWord,seq,ans,map);
    }
    return ans;
}

int main()
{

}