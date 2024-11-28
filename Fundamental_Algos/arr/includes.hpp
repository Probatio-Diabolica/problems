#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<climits>
#include<deque>
#include<map>
#include<queue>
using namespace std;
template<typename Type>
std::ostream& operator<<(std::ostream& stream , std::vector<Type> vec)
{
    for(auto i : vec) stream <<i<<" , ";
    return stream;
}