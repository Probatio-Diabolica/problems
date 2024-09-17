#include<vector>

int majorityElement(std::vector<int>& nums) 
{
        int count =0,element=nums[0];
        for(auto el:nums)
        {
            count += (element==el) ? 1 : -1;
            if(count==0) 
            {
                element=el;
                count=1;
            }
        }
        return element;
}
int main()
{
    
}