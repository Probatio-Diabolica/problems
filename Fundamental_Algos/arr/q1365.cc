
#include"includes.hpp"

void decrease(std::vector<int>& curr,std::vector<int> point)
{
    if(curr[0] > point[0]) --curr[0];
    
    if(curr[1] > point[1]) --curr[1];
}

void increase(std::vector<int>& curr,std::vector<int> point)
{
    if(curr[0] < point[0]) ++curr[0];
    
    if(curr[1] < point[1]) ++curr[1];
}


int minTimeToVisitAllPoints_no_good(vector<vector<int>>& points) 
{
    int time=0;

    //O(N * 2)
    for(int i =0;i<points.size()-1;i++)
    {
        std::vector<int> curr=points[i];
        std::vector<int>dest = points[i+1];
        while(curr[0] != dest[0] or curr[1] != dest[1])
        {
            decrease(curr,dest);
            increase(curr,dest);
            ++time;
        }
    }

    return time;
}


// best
int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int time=0;

    for(int i=0;i<points.size()-1;i++)
    {
        std::vector<int> curr=points[i];
        std::vector<int>dest = points[i+1];
        time += max(std::abs(dest[0]-curr[0]),std::abs(dest[1]-curr[1]));
    }
    return time;
}

int main()
{
    std::vector<vector<int>> a={{1,1},{3,4},{-1,0}};
    std::cout<<minTimeToVisitAllPoints(a);
}