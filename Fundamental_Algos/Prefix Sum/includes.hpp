#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<climits>
#include<deque>
#include<map>

using namespace std;

std::ostream& operator<<(std::ostream& stream , const std::vector<int>& vec)
{
    for(int i : vec) stream <<i<<" , ";
    return stream;
}