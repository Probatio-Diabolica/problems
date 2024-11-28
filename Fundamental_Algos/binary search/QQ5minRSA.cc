#include<iostream>
#include<vector>

int findMin(std::vector<int>& nums) 
{
    int space=nums.size();
    if(space==1) return nums[0];
    else if(space==2) return (nums[0]<nums[1]) ? nums[0] : nums[1]; 
    int head=0,tail=space-1,check=nums[0],mid=head+(tail-head)/2,lowest;
    while(head<=tail)
    {
        lowest=nums[mid];
        if(lowest==check) return check;
        else if(lowest>check)head=mid+1;
        else 
        {
            tail=mid-1;
            check=lowest;
        }
        mid=head+(tail-head)/2;
    }
    return (lowest <= check) ? lowest: check;
}

int main()
{
    std::vector<int> a{2,0,1};
    std::cout<<findMin(a);

}