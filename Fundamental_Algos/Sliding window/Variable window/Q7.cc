#include<iostream>
#include<vector>
int numSubarrayProductLessThanK(std::vector<int>& nums, int k) 
{
    int i=0,j=0,product=1,result=0,n=nums.size();
    while(j<n) {
        if(nums[j]>=k) {
            i=++j;
            product=1;
            continue;
        }
        product *= nums[j];
        while(product >= k && i<=j) {
            product /= nums[i++];
        }
        result += j-i+1;
        j++;
    }
    return result;

}

int main()
{
    std::vector<int> a={10,9,10,4,3,8,3,3,6,2,10,10,9,3};
    std::cout<<numSubarrayProductLessThanK(a,19);
}