Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?

https://leetcode.com/problems/rotate-array/description/



<SOLUTION:>

# Brute Force:---------------------------------------------------------------------------------------------------------
let's  rake a look at some sample sizes:
a=[1,2,3,4,5] key=[4]
sol=> [2,3,4,5,1]

key=[3]
sol=> [3,4,5,1,2]

key=[2]
sol=> [4,5,1,2,3]
>hence we can say, that the last 'key' no. of elements will get positioned to the begining of the array
T.C=> O(N)
S.C=> O(N)

# Optimal Solution:------------------------------------------------------------------------------------------------------

Let's take another look at the sample sizes:
a=[1,2,3,4,5] k=2
sol=> [4,5,1,2,3]
this can be achieved by:
> first, reversing the whole array
   <i1: (5,4,3,2,1)

>second, devide the array into two with the help of "k"
   <i2: (5,4 [k] 3,2,1)

>now, reverse the two parts of the array
   <i3: (4,5 -- ,1,2,3)

T.C=O(N)
S.C=O(1)<!--//because we used no extra space-->