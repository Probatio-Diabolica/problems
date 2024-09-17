#include<iostream>
#include<vector>

void swap(int *a, int *b)
{
    int temp=*b;
    *b=*a;
    *a=temp;
}

int partition(std::vector<int>& nums,int head,int tail)
{
        int pivot=nums[head];
    int p_index=head;
    for(int i=head+1;i<=tail;i++)
    {
        if(pivot>nums[i]) //flow changer
        {
            p_index++;
            swap(&nums[i],&nums[p_index]);
        }
    }
    swap(&nums[head],&nums[p_index]);
    return p_index;
}

void Qs(std::vector<int>&nums,int head,int tail)
{
    if(head<tail)
    {
        int pivot=partition(nums,head,tail);
        Qs(nums,head,pivot-1);
        Qs(nums,pivot+1,tail);
    }
}

int findLHS(std::vector<int>& nums) 
{

    // int count=0,left=0,right=1;
    // Qs(nums,0,nums.size()-1);
    // while(right<nums.size())
    // {
    //     if(nums[right]-nums[left]==1)
    //     {
    //         count=(count >(right-left+1)) ? count : (right-left+1); 
    //     }
    //     while((nums[right]-nums[left]) >1)
    //     {
    //         ++left;
    //     }
    //     ++right;
    // }
    // return count;
    int res = 0, left = 0, right = 1, curIndex = 0;
        Qs(nums,0,nums.size()-1);
        while (right < nums.size()) {
            if (nums[right] - nums[left] == 1) {
                res=(res> (right - left +1)) ? res : (right - left +1);
            }
            while(nums[right] - nums[left] > 1){
                ++left;
            }
            ++right;
        }
        return res;
}

int main()
{
    std::vector<int> a={1,3,2,2,5,2,3,7};
    std::vector<int> b={1,2,3,4};
    std::vector<int> c={1,1,1,1};
    std::cout<<findLHS(a)<<"\n";
    std::cout<<findLHS(b)<<"\n";
    std::cout<<findLHS(c)<<"\n";
    // std::qsort()
}