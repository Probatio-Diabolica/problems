#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void printvec(vector<int> a)
{
    for(int i =0;i<a.size();i++)
    {
        std::cout<<a[i]<<" , ";
    }
}
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mp;
    for(int  i=0;i<nums.size();i++)
    { 
        if(mp.count(target-nums[i])) 
        {
            return vector<int>{mp[target-nums[i]],i};
        }
        mp[nums[i]]=i;
    }
    return vector<int>{0};
}

int main()
{
    vector<int> a={2,7,11,15};
    printvec(twoSum(a,9));
}