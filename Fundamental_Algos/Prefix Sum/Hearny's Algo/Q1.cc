#include"includes.hpp"


//Note: It's O(N) in time however it takes some space[ O(n) ?] as well
int numberOfSubarrays(std::vector<int>& nums, int k,int x) {
    int ans=0,count=0,target;
    std::unordered_map<int,int> map;
    map[0]=1;
    for(int val: nums)
    {
        count+=val&1;
        target = count-k;
        if(target>=0) ans+=map[target];
        map[count]+=1;
    }
    return ans;
}

//* This one uses No extra space
int numberOfSubarrays(std::vector<int>& nums, int k) 
{
    
}
int main()
{
    std::vector<int> a={2,2,2,1,2,2,1,2,2,2};
    std::cout<<numberOfSubarrays(a,2);
}