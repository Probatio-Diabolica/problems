#include"include.hpp"

def removeDuplicates( nums) -> int:
    left ,right=0,0
    while(right<len(nums)):
        counter=1
        while(right+1 < len(nums) and nums[right]==nums[right+1]):
            counter+=1
            right+=1
        for i in range (min(2,counter)):
            nums[left]=nums[right]
            left+=1
        right+=1
    return left
# int main()
# {
#     Array vec={1,1,1}, vec2={0,0,1,1,1,1,2,3,3};

#     std::cout<< vec<<"\n";
#     std::cout<<removeDuplicates(vec)<<"\n";
#     std::cout<<vec;
# }

nums=[0,0,1,1,1,1,2,3,3]
print(removeDuplicates(nums))