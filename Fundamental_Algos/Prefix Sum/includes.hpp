#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<climits>
#include<deque>

std::ostream& operator<<(std::ostream& stream , std::vector<int> vec)
{
    for(int i : vec) stream <<i<<" , ";
    return stream;
}