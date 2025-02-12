#include<iostream>
#include<vector>

int numberOfSubarrays(std::vector<int>& nums, int k) {
    int right=0,left=0,poss=0,count;
    for(count=0;count<k and right<nums.size();right++)
    {
        if(nums[right]%2!=0) count++;
    }
    ++poss;
    while(right<nums.size())
    {

        // insert
        if(count<k or nums[right]%2==0)
        {
            if(nums[right]%2!=0)count++;

            if(count==k) poss++;
        }
        // delete
        
        
    }

    return poss;
}

int main()
{
    std::vector<int> a={1,2,3,4,5,6};
    std::cout<<numberOfSubarrays(a,2);
}