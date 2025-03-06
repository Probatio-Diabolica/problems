#include "includes.hpp"

bool canPartition(std::vector<int>& nums) 
{
    int sum=0;
    for(int el: nums) sum+=el;
    if(sum&1) return false;


    int point=sum/2;
    std::set<int> holder={0};
    
    
    for(int i: nums) holder.insert(i);

    auto it= holder.begin();
    int summ =0,temp=0;
    while(it!=holder.begin())
    {

        summ+= *it;
        for(int i=temp;i<nums.size();i++)
        {
            summ+=nums[i];
            if(summ==point ) return true;
            summ-=nums[i];
        }
        temp++;
        it++;
    }

    return false;        
}


int main()
{
    std::vector<int> a={1,5,11,5},b={1,2,3,5},c={3,3,3,4,5},d={1,2,5};
    std::cout<<canPartition(a)<<"\n";
    std::cout<<canPartition(d);
}