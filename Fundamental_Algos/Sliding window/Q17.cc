#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;
vector<string> findRepeatedDnaSequences(string s) 
{
    vector<string> res={};
    unordered_map<string,int> map;
    if(s.length() <=10) return res;

    for(int i=0;i<s.size()-9;i++)
    {
        string substring = s.substr(i, 10);
            if (map.count(substring)) {
                if (map[substring] == 1) {
                    res.push_back(substring);
                }
                map[substring]++;
            } else {
                map[substring] = 1;
            }
    } 
    return res;
    
}

int main()
{
    std::string dna1 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    std::vector<std::string> result1 = findRepeatedDnaSequences(dna1);
    
    std::cout << "Result for " << dna1 << ":\n";
    for (const auto& seq : result1) {
        std::cout << seq << " ";
    }
    std::cout << "\n\n";
    
    std::string dna2 = "AAAAAAAAAAA";
    std::vector<std::string> result2 =findRepeatedDnaSequences(dna2);
    
    std::cout << "Result for " << dna2 << ":\n";
    for (const auto& seq : result2) {
        std::cout << seq << " ";
    }
    std::cout << "\n";
    
    return 0;
}