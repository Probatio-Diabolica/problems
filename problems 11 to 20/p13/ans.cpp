#include<iostream>
#include<vector>
using namespace std;

int searchInsert(vector<int>& nums, int trgt) {
        int head = 0; int tail = nums.size(); int mid = head+(tail-head) / 2; 
        while (tail > head){
            if (nums[mid] == trgt)
                return mid; 
            else if (nums[mid] > trgt)
                tail = mid; 
            else 
                head = mid + 1; 
            mid = (head+tail)/ 2;
        }
        return mid; 
    }


int main(int argc , char **argv){
    vector<int> nums={1,3,5,7};
    cout<<searchInsert(nums,2);//2
    return 0;
}