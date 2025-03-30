#include <iostream>
#include<vector>

int findKthPositive(std::vector<int>& arr, int k) 
{
    int left=0,right=arr.size()-1;
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if((arr[mid] - (mid+1)) < k)
        { 
            left = mid+1;
        }else
        { 
            right = mid-1;
        }
    }
        return ((arr[right]-right) ==1) ? arr[right] + k : arr[right]+(k-right);
}

int main()
{
    std::vector<int>arr = {3,4,9,10,12,13},x{1,2,3,4},y{2,3,4,7,11}; int k = 6;
    std::cout<<findKthPositive(arr,  4)<<'\n';
    std::cout<<findKthPositive(y, 5)<<'\n';
    std::cout<<findKthPositive(x, 4)<<'\n';

}