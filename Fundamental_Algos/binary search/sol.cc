#include<iostream>
#include<vector> 
int search(std::vector<int>& nums, int target) {
        int head=0,tail=nums.size()-1,mid=head+(tail-head)/2;
        while(head<=tail)
        {
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target)
            {
                head=mid+1;
            }else
            {
                tail=mid-1;
            }
            mid=head+(tail-head)/2;
        }
        return -1;
    }

int main()
{
    std::vector<int> a={-1,0,3,5,9,12};
    std::cout<<search(a,12);
}
