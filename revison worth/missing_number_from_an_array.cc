#include<iostream>
#include<vector>
int missingNumber(std::vector<int>& nums) 
{
    int n = nums.size();
    int ans =0;
    for(int i =1;i<=n;i++){
        ans = ans ^ i;
    }
    for(int i =0;i<nums.size();i++){
        ans= ans^nums[i];
    }
    return ans;
}
// https://leetcode.com/problems/missing-number/solutions/4754401/beats-98-users-4-approaches-c-java-python-javascript-explained/
int main()
{
    int ans1 =0;
    for(int i =1;i<=10;i++){
        ans1 = ans1 ^ i;
    }
    int ans2 =0;
        for(int i =1;i<=9;i++){
            ans2 = ans2 ^ i;
        }
        int ans3=ans1^ans2;
    std::cout<< ans3;
}