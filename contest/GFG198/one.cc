#include "include.hpp"
#include <unordered_map>

int rearrange(vector<int>& pages, vector<int>& shelf) {
    // shelf and <sum , max number>
    std::unordered_map<int, std::pair<int,int>> map;

    for(int i=0;i<pages.size();i++)
    {
        map[shelf[i]].first += pages[i];
        map[shelf[i]].second = (pages[i] > map[shelf[i]].second) ? pages[i] : map[shelf[i]].second; 
    }
    int order=0;
    for(int i=0;i<pages.size();i++)
    {
        order += map[shelf[i]].first - map[shelf[i]].second; 
        map[shelf[i]].first =map[shelf[i]].second;
    }
    return order;
}

int main()
{
    iArray x{5,11,6}, y{2,7,6};
    std::cout<<rearrange(x, y);
}