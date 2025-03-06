#include"includes.hpp"

// Approach 1 : n log k
std::vector<int> topKFrequent__pq(std::vector<int>& nums, int k) {
    //1 init
    typedef std::pair<int,int> p;
    std::unordered_map<int,int> map;
    for(int i =0;i<nums.size();i++)
    {
        ++map[nums[i]];
    }

    //2. defining a min heap
    std::priority_queue<p,std::vector<p>,std::greater<p>> pq;

    //3. pushing elements in min heap,while maining the size of k
    for(auto &it:map) // O(n log k)
    {
        int value = it.first;
        int freq = it.second;

        pq.push({freq,value}); //log n

        if(pq.size() > k) //removes the top most element
        {
            pq.pop();
        }
    }

    //4 result 
    std::vector<int> res={};
    while(!pq.empty())
    {
        res.push_back(pq.top().second);
        pq.pop();

    }
    return res;
}

//app 2: bucket sort
std::vector<int> topKFrequent(std::vector<int>& nums, int k) 
{
    int n=nums.size();
    std::unordered_map<int ,int> map;

    //preparing the frequency
    for(int &num: nums)
    {
        ++map[num];
    }

    std::vector<std::vector<int>> bucket(n+1);



    // Filling the bucket array
    for(auto &it:map)
    {
        int element= it.first;
        int freq = it.second;

        bucket[freq].push_back(element);
    }

    //harvesting the top k elements
    std::vector<int> result;

    for(int i=n;i>=0;i--)
    {
        if(bucket.size()==0) continue;

        while(bucket[i].size()>0 && k > 0)
        {
            result.push_back(bucket[i].back());
            bucket[i].pop_back();
            --k;
        }
    }

    return result; 
}


int main()
{
    std::vector<int> a={1,1,1,1,3,2,2,2,2};
    std::cout<<topKFrequent(a,2);
}