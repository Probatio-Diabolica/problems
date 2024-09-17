/*

* We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

* Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

* A subsequence of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

// Example 1:

Input: nums = [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].

// Example 2:

Input: nums = [1,2,3,4]
Output: 2

// Example 3:

Input: nums = [1,1,1,1]
Output: 0


// Constraints:

    1 <= nums.length <= 2 * 104
    -109 <= nums[i] <= 109
*/ 


#include<iostream>
#include<vector>

void swap(int *a,int*b)
{
   int temp =*a;
    *a=*b;
    *b=temp;
    // *a+=*b;
    // *b=*a-*b;
    // *a=*a-*b;
}

int pivot(std::vector<int> & arr,int head,int tail)
{
    int pivot=arr[head];
    int index=head;
    for(int i=head+1;i<=tail;i++){
        if(pivot>arr[i])
        {
            index++; //first index incrementation
            swap(&arr[i],&arr[index]); // we won't swap pivot here just the element at 'index' to i.
        }
    }
    swap(&arr[index],&arr[head]);
    return index;
}


void QS(std::vector<int> &arr,int head,int tail)
{
    if(head<tail){
        int index=pivot(arr,head,tail);
        QS(arr,head,index-1);
        QS(arr,index+1,tail);
    }
}

int findLHS(std::vector<int>& nums) 
{
    int old=nums[0],winSize=0,maxWS=0,temp=old;
    QS(nums,0,nums.size()-1);
    for (size_t i=0;i<nums.size();i++)
    {
        if(i==old) winSize++;
        if(i==old+1) 
        {
            winSize++;
        }
        else
        {
            maxWS = winSize>maxWS ? winSize : maxWS;
            winSize=0;
        }

    }
    
    return 0;
}

std::ostream& operator<<(std::ostream& stream,std::vector<int>& vec)
{
    for(size_t i =0;i<vec.size();i++) stream <<vec[i]<<" , ";
    return stream;
}

int main()
{
    std::vector<int> a {1,2,1,2,3,1,2,7,8,6,1};
    QS(a,0,10);
    std::cout<<a;
}