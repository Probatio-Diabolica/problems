#include"includes.hpp"
#include<numeric>
// memoized but works
// int states[205][20005];
// bool work(int idx,int sum, vector<int> nums)
// {
//     if(sum==0) return true;
//     if(idx<0) return false;
//     if(states[idx][sum]!=-1) return states[idx][sum];
//     //// exclude
//     bool result=work(idx-1,sum,nums);
//     //// Include
//     if((!result) and (sum>=nums[idx])) result = work(idx-1,sum-nums[idx],nums);

//     return states[idx][sum]=result;
// }

// bool canPartition(vector<int>& nums) {
//     int sum=0;
//     for(int i : nums) sum+=i;
//     if(sum&1) return false;
//     std::memset(states,-1,sizeof(states));
//     sum >>=1;
//     return work(nums.size()-1,sum,nums);
// }

bool canPartition(vector<int>& nums) {
    int tSum=accumulate(nums.begin(),nums.end(),0); //Die funktion ist in der Header-daten <numeric> definiert
    if(tSum%2)return false;
    vector<bool> prev(20001,0),curr(20001,0);
    prev[0]=curr[0]=1;
    prev[nums[0]]=1;
    for(int i=1;i<nums.size();i++){
        for(int k=1;k<=tSum/2;k++){
            bool noPick=prev[k];
            bool pick=(k>=nums[i])?prev[k-nums[i]]:0;
            curr[k]=pick|noPick;
        }
        prev=curr;
    }
    return  prev[tSum/2];
        
}

int main()
{
    iArray a={1,2,3,4};
    std::cout<<canPartition(a);
}