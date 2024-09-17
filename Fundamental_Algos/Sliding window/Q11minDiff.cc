
/*
You are given a 0-indexed integer array nums, where nums[i] represents the score of the ith student. You are also given an integer k.

Pick the scores of any k students from the array so that the difference between the highest and the lowest of the k scores is minimized.

Return the minimum possible difference.

 

Example 1:

Input: nums = [90], k = 1
Output: 0
Explanation: There is one way to pick score(s) of one student:
- [90]. The difference between the highest and lowest score is 90 - 90 = 0.
The minimum possible difference is 0.

Example 2:

Input: nums = [9,4,1,7], k = 2
Output: 2
Explanation: There are six ways to pick score(s) of two students:
- [9,4,1,7]. The difference between the highest and lowest score is 9 - 4 = 5.
- [9,4,1,7]. The difference between the highest and lowest score is 9 - 1 = 8.
- [9,4,1,7]. The difference between the highest and lowest score is 9 - 7 = 2.
- [9,4,1,7]. The difference between the highest and lowest score is 4 - 1 = 3.
- [9,4,1,7]. The difference between the highest and lowest score is 7 - 4 = 3.
- [9,4,1,7]. The difference between the highest and lowest score is 7 - 1 = 6.
The minimum possible difference is 2.

 

Constraints:

    1 <= k <= nums.length <= 1000
    0 <= nums[i] <= 105




*/

#include<iostream>
#include<vector>

void swap(int* a,int* b)
{
    int temp=*b;
    *b=*a;
    *a=temp;
}

int partition(std::vector<int> &nums, int head,int tail)
{
    int pivot=nums[head];
    int p_index=head;
    for(int i=head+1;i<=tail;i++)
    {
        if(pivot>nums[i]) //flow changer
        {
            p_index++;
            swap(&nums[i],&nums[p_index]);
        }
    }
    swap(&nums[head],&nums[p_index]);
    return p_index;
}

void QS(std::vector<int>  &num,int head,int tail)
{
    if(head<tail)
    {
        int pivot_In=partition(num,head,tail);
        QS(num,head,pivot_In-1);
        QS(num,pivot_In+1,tail);
    }
}

void print(std::vector<int> &n)
{
    for(int i=0;i<n.size();i++)
    {
        std::cout<<n[i]<<" , ";
    }
}

int minimumDifference(std::vector<int>& nums, int k) {
    QS(nums,0,nums.size()-1);
    int maxDiff=nums[nums.size()-1],diff;
    for(size_t i=0;i<nums.size()-k+1;i++)
    {
        diff= nums[i+k-1] - nums[i];
        maxDiff=maxDiff<diff ? maxDiff : diff;
    }
    return maxDiff;
}

int main()
{
    std::vector<int> vec={9,4,1,7};
    std::cout<<minimumDifference(vec,2);
}