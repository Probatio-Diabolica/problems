#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int bigga(int a,int b){
        if(a>b){
            return a;
        }else{
            return b;
        }
    }

    int maxSubArray(vector<int>& nums) 
    {
        int sum=0;
        int max=nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            sum=sum+nums[i];
            max=bigga(max,sum);
            sum=bigga(sum,0);
        }
        return max;
    }
};

int main(int argc, char* argv[]){
    Solution sol;
    vector<int> abc={-2,1,-3,4,-1,2,1,-5,4};
    cout<< sol.maxSubArray(abc);
    return 0;
}