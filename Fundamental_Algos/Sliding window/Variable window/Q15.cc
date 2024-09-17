#include<vector>
#include<iostream>
using namespace std;
int Calculate(vector<int>& nums, int target) {
    int front = 0;
    int end = 0;
    int count = 0;
    int sum = 0;
    
    for (end = 0; end < nums.size(); end++) {
        sum = sum + nums[end];
        while (sum > target && front <= end) {
            sum = sum - nums[front];
            front++;
        }
        count = count + end - front + 1;

    }
    
    return count;

}

int numSubarraysWithSum(vector<int>& nums, int target) {
    
    return Calculate(nums,target)-Calculate(nums,target-1);   
}

int main()
{
    vector<int> a={1,0,0,0,1,1,1,0,1};
    cout<<numSubarraysWithSum(a,0)<<endl;
}