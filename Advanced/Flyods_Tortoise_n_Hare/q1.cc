#include<iostream>
#include<vector>



int findDuplicate(std::vector<int>& nums) {
    int slow=0, fast=0;
    while (true)
    {
        slow=nums[slow];
        fast=nums[nums[fast]];
        if (slow==fast) break;
    }
    int slow2=0;
    while(true)
    {
        slow=nums[slow];
        slow2=nums[slow2];
        if (slow==slow2) return slow;
    }

}



int main()
{
    std::vector<int> a={1,2,3,4,4},b={1,2,3,2,4},c={2,2,2,2,2};
    std::cout<<findDuplicate(a);
}