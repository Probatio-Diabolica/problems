#include"includes.hpp"
#include <algorithm>
#include <iterator>
#include <queue>
#include <vector>


int countDays(int days, vector<vector<int>>& meetings) {
    std::sort(meetings.begin(),meetings.end());
    int freeDays=0,lastEnd=0;
    for(vector<int> &v : meetings)
    {
        int start=v[0],end=v[1];
        // look for free day
        if(start > lastEnd+1)
        {
            freeDays+=start-lastEnd-1;
        }

        //this is just leftovers
        lastEnd=std::max(lastEnd,end);
    }

    freeDays+=days-lastEnd;
    return freeDays;
}


int main()
{
    // iMat meetings={{5,7},{1,3},{9,10}};
    iMat meetings={{37,40},{16,19},{20,25},{3,55},{16,38},{2,44},{54,58},{14,24},{13,21}};

    std::cout<<countDays(65, meetings);

}