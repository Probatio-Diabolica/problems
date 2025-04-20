#include "include.hpp"
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) 
{
    vector<long long> answer(nums1.size());
    unordered_map<int, int> mp,mp2;
    int checker =nums1.size();
    
    for(int ori =0;ori<checker;ori++)
    {
        mp[nums1[ori]] = nums2[ori];
        mp2[nums1[ori]] = ori;
    }
    
    sort(nums1.begin(),nums1.end());
    for(int ori =0;ori<checker;ori++)
    {
        priority_queue<int> maxHeap;
        int times=0;
        for(int smol = 0;nums1[smol] < nums1[ori];smol++)
        {
            maxHeap.push(mp[nums1[smol]]);
        }
        while((!maxHeap.empty()) and times<k )
        {
            answer[mp2[nums1[ori]]]+=maxHeap.top();
            // int x = answer[mp2[nums1[ori]]];
            maxHeap.pop();
            ++times;
        }
    }
    return answer;
}

int main()
{
    iArray x1{18,11,24,9,10,11,7,29,16},x2{28,26,27,4,2,19,23,1,2};
    std::cout<<findMaxSum(x1, x2, 1);
    // [26,23,28,23,23,23,0,28,26]
}