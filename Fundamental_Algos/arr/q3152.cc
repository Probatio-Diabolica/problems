#include"includes.hpp"

//works but not with huge test cases, it is brute force, TC = O(N * K)
// to do -> O(N) or N(n log n) or (n + log n)

vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>>& queries) {
    std::vector<bool> res(queries.size(),true);
    for(int i =0;i<queries.size();i++)
    {
        //start points
        int start=queries[i][0];
        int end=queries[i][1];
        bool star=true;
        while(start<end)
        {
            bool next=nums[start+1] & 1;
            bool now=nums[start++] & 1;
            if(now==next)
            {
                star= false;
                continue;
            }
        }
        res[i]=star;
    }
    return res;
}

int main()
{
    std::vector<int> a{4,3,1,6};
    std::vector<std::vector<int>> x={{0,2},{2,3}};
    std::cout<<isArraySpecial(a,x);
}