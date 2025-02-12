#include<iostream>
#include<vector>
#include<queue>


class KthLargest {
public:
    int K;
    std::priority_queue<int,std::vector<int>,std::greater<int>> pq;
    
    KthLargest(int k, std::vector<int>& nums) {
        K = k;
        for(int i =0 ; i< nums.size();i++)
        {
            pq.push(nums[i]);
            if(pq.size()>K) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()> K)pq.pop();
        return pq.top();
    }
};


int main()
{
    
}