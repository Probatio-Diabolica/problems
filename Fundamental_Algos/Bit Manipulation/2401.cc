#include <algorithm>
#include<iostream>
#include <ostream>
#include <vector>

using iArray = std::vector<int>;
[[nodiscard]]int longestNiceSubarray__op__(std::vector<int>& nums)
{
    int n = nums.size();

    int sol=1;

    int mask =0;
    for(int i =0, j = 0; j<n;j++)
    {
        while((mask & nums[j]) !=0)
        {
            mask ^= nums[i];
            i++;
        }
        sol = std::max(sol,j-i+1);
        mask|=nums[j];
    }

    return sol;
}
[[nodiscard]]int longestNiceSubarray(std::vector<int>& nums) {
    int n = nums.size();

    int sol=0;

    for(int i =0 ;i<n;i++)
    {
        int mask = 0;
        for(int j=i;j<n;j++)
        {
            if((mask & nums[j]) !=0) break;
            
            sol = std::max(sol,j-i+1);
            mask |= nums[j]; 
        }

    }
    return sol;
}

std::ostream& operator<<(std::ostream& stream, std::vector<int>& vec)
{
    for(int i : vec) stream << i << " ";
    return stream;
}
int main()
{
    iArray x {2,3,5,7,11,13};
    // std::cout<<(3&49)<<'\n';
    std::cout<<longestNiceSubarray(x);
    // std::cout<<x;
}
