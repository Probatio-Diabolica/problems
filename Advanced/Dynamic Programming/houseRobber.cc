#include"includes.hpp"

int max(int a, int b)
{
    return a>b ? a :b;
};

int work(int idx,iArray &nums,iArray& states)
{
    if(idx<0) return 0;
    if(states[idx]!=-1) return states[idx];
    int solution=0;
    for(int i=2;i<=idx;i++)
    {
        solution=max(solution,work(idx-i,nums,states)) ;
    }
    return states[idx]=(solution+nums[idx]);
}

int rob2(vector<int>& nums) 
{
    if(nums.size()==1) return nums[0];
    iArray states(nums.size(),-1);
    return max( work(nums.size()-1 , nums,states)  , work(nums.size()-2 , nums,states) );
}


//// Lol best solution
int rob(vector<int>& nums) 
{
    if(nums.size()==1) return nums[0];
    else if(nums.size()==2) return max(nums[0],nums[1]);

    iArray states(nums.size(),0);
    states[0]=nums[0],states[1]=nums[1], states[2]=states[0]+nums[2];
    int sol=max(states[2],states[1]);
    for(int i = 3;i<nums.size();i++)
    {
        states[i]=max(states[i-2],states[i-3]) + nums[i];
        sol=max(states[i],sol);
    }
    return sol;
}

int main()
{
    iArray x={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99};
    cout<<rob(x);
}