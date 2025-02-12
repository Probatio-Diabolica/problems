#include"includes.hpp"

int findKthLargest(vector<int>& nums, int k) {
    std::priority_queue<int> maxHeap;

    int lim = nums.size()-k+1;
    for(int i =0;i<nums.size();i++)
    {
        maxHeap.push(nums[i]);
        if(maxHeap.size() > lim ) maxHeap.pop(); 
    }
    return maxHeap.top();
}

int main()
{
    iArray x = {3,2,3,1,2,4,5,5,6};
    std::cout<<findKthLargest(x,4);
}