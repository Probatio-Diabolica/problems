#include<iostream>
#include<vector>

using namespace std;

// void subSequence(vector<vector<int>>& sol,int curr,vector<int>& nums,int lim)
// {
//     if (curr >= lim) return;

//     vector<int> v;
//     int temp = curr;
//     int idx=nums.size()-1;
//     while(temp>0)
//     {
//         if(temp&1) v.push_back(nums[idx]);
//         temp>>=1;
//         --idx;
//     }

//     sol.push_back(v);
//     subSequence(sol, curr + 1, nums, lim);
// }

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> sol;
    int lim = 1<<nums.size();
    sol.reserve(lim);
    for(int idx  = 0; idx < lim;idx++)
    {
        std::vector<int> v;
        for(int idx1 = 0;idx < nums.size();idx++)
        {
            if(idx & (1 << idx)) v.push_back(nums[idx]);
        }
        sol.push_back(v);
    }
    return sol; 
}