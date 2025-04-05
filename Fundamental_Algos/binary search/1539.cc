#include <iostream>
#include<vector>

int findKthPositive(std::vector<int>& arr, int k) 
{
    int left=0,right=arr.size()-1;
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if((arr[mid] - (mid+1)) < k)  left = mid+1;
        else right = mid-1;
    }   
    return right+1+k; 
    // return left + k; works too
}

int main()
{
    std::vector<int>arr = {4,7,8},x{1,2,3,4},y{2,3,4,7,11}; 
    std::cout<<findKthPositive(arr,  3)<<'\n';
    std::cout<<findKthPositive(y, 5)<<'\n';
    std::cout<<findKthPositive(x, 4)<<'\n';
}