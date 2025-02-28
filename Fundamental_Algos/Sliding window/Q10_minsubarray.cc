/*

* You are given an integer array nums consisting of n elements, and an integer k.

!! Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.


// Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

// Example 2:

Input: nums = [5], k = 1
Output: 5.00000

 

$ Constraints:

->    n == nums.length
->    1 <= k <= n <= 105
->    -104 <= nums[i] <= 104



*/


#include<iostream>
#include<vector>

double findMaxAverage(std::vector<int>& nums, int k) 
{
    double sum=0.00;
    for(short int i=0;i<k;i++) sum+=  nums[i];
    double temp=sum;
    for(short int i=1;i<=nums.size()-k;i++) 
    {
        temp    +=  (nums[i+k-1]-nums[i-1]);
        sum     =   temp>sum ? temp : sum;
    } 
    return double(sum)/k;       
}


int main()
{
    std::vector<int> a={1,12,-5,-6,50,3};
    std::vector<int> b={5};
    std::vector<int> c={5,9,0,8,7};
    std::cout<<findMaxAverage(a,4)<<"\n";
    std::cout<<findMaxAverage(b,1)<<"\n";
    std::cout<<findMaxAverage(c,2)<<"\n";
}