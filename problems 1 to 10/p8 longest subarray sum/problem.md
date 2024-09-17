# Maximum Subarray-----------------------------------------------
Given an integer array nums, find the 
subarray with the largest sum, and return its [sum].

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 
link: https://leetcode.com/problems/maximum-subarray/description/
Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.


# Solution:         [Intuitive]   T.C = O[N^2]-------------------------------------------------------

>Let an array with name `X` be [a,b,c,d,e]

   <then, all the sub arrays be : = [a],[a,b],[a,b,c],[a,b,c,d],[a,b,c,d,e],[b],[b,c]... so on.
   -    hence, we can say we just need the sum of all sub arrays and then we need to return the sum with highest value.>

<!--
task: traversing through the subarrays while checking wil currentSum is bigger than sum of not?
note: sum =0 ; currentSum=0:
    Pseudo code will be :

        //  start while(pointer hasn't reached the end of the array):
        //
        //        start while(pointer<size //pointer is less than the lenght of array):
        //              if(currentSum > sum) => sum = currentSum
        //        end of loop
        //
        //        pointer++
        //
        //  end of loop

-->
# Solution:         [Kadane's_Algorithm]

>initially set sum=0 and max=`first element of array`.  
> To solve this problem we will be doing three things per iteration:  
    >calculate sum.
    >update max. 
        >Max will be updated by using a `bigga` funtion. `bigga will contain old max and current sum`
            >`Bigga` function will take two numbers as parameters and will return the bigger number  
    >set sum = 0 , if sum is a negetive integer


