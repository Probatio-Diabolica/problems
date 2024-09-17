"""
!!Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. 
-> It is given that all array elements are distinct.

Note:-  'l' and 'r' denotes the starting and ending index of the array.

// Example 1:

// Input:
// N = 6
// arr[] = 7 10 4 3 20 15
// K = 3
// Output : 7
// Explanation :
// 3rd smallest element in the given 
// array is 7.
// Example 2:

// Input:
// N = 5
// arr[] = 7 10 4 20 15
// K = 4
// Output : 15

        Explanation :
        4th smallest element in the given 
        array is 15.

Task: You don't have to read input or print anything. Your task is to complete the function kthSmallest() which takes the array arr[], integers l and r denoting the starting and ending index of the array and an integer K as input and returns the Kth smallest element.


->  Expected Time Complexity: O(n)
->  Expected Auxiliary Space: O(log(n))

Constraints:
        1 <= N <= 105
        1 <= arr[i] <= 105
        1 <= K <= N
"""
import random as rd



def Qsort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]#just like in partition , we take first element as a pivot
        less = [x for x in arr[1:] if x <= pivot] #less contains that side of array which is supposed to be the smaller one
        greater = [x for x in arr[1:] if x > pivot]# greater contains the rray which is supposed to be the greater one

        return Qsort(less) + [pivot] + Qsort(greater)#smaller area < Pivot> Bigger area


if __name__=="__main__":
        arr=[]
        for i in range(0,10):
                arr.append(rd.randint(10,893))
        print(arr)
        # swap(arr,2,4)
        arr=Qsort(arr)
        print(arr)

"""
void sort(int* nums,int size){
    for (int i = 1; i < size; i++)
    {   
        if(nums[i]>nums[i+1] && i<size-1 && i>=1 ){
            swap(&nums[i+1],&nums[i]);
            i=i-2;
        }else if(nums[i]>nums[i+1] && i<size-1){
            swap(&nums[i+1],&nums[i]);
        }
        
    }
    
}"""
