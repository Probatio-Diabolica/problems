#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
        int pivoit(vector<int> &nums){
            int head=0,tail=nums.size()-1;
            int mid=tail/2;
            while(head<tail){
                if(nums[0]>nums[mid]){
                    // Normal situation
                    tail=mid;
                }else{
                    head=mid+1;
                }
                mid=head+ ((tail-head)/2);
            }
            return head;
        }
        int num(vector<int> &nums,int target){
            int patchy=pivoit(nums);
            int ans=patchy;
            if(target>nums[patchy]){
                //!!    search in left side
                //-> head=0;tail=patchy-1
            }else if(target<nums[patchy]){
                //!!    search in right side
                //-> head=patchy;tail=size-1;
            }else{
                return patchy;
            }
            return ans;
        }
};
int main(int argc, char **argv){
    return 0;
}