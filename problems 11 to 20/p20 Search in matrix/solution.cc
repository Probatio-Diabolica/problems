#include <iostream>
#include <vector>

void solution(std::vector<std::vector<int>>& vec , int target )
{
    int mid=vec.size()/2,head=0,tail=vec.size();
    while(head<tail)
    {
        if(vec[mid][0]<=target && vec[mid][vec[mid].size()-1] >=target) 
        {
            // //Found the one which is needed to be searched
        }
        if(vec[mid][vec[mid].size()-1] <target)
        {
            
            tail=mid-1;
        }
        if(vec[mid][0]>target && vec[mid][vec[mid].size()-1] <target)
        {
            //!! this one picks decides if
            tail=mid-1;
        }
        mid = head + tail /2;
    }
}

int main()
{
    std::vector<std::vector<int>> Test = { {1,2,3,4}, {5,6,7,8}, {11,22,33,44,55},{90,91}};
    int m=2;
    // std::cout<<Test[0][1]<<" "<<Test[m][Test[m].size()-1];
}

