#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<climits>
#include<deque>
#include<map>
#include<unordered_set>
std::ostream& operator<<(std::ostream& stream , std::vector<int> vec)
{
    for(int i : vec) stream <<i<<" , ";
    return stream;
}