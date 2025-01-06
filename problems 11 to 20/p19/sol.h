#pragma once
#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>

class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        bool valid=false;
        std::unordered_map<int,int> mp;
        
        // storing frequency
        for(auto num: arr) mp[num]++;

        // check the count
        std::unordered_set<int> set;
        for(auto it: mp)
        {
            int frequency=it.second;
            set.insert(frequency);
        }
        valid = set.size()==mp.size();
        return valid;

    }
};