#include<iostream>
#include<vector>

std::ostream& operator<<(std::ostream& stream, std::vector<int> vec)
{
    for(int i:vec) stream<<i<<" ";
    return stream;
}

std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> res(nums1.size(),-1);
    int stack[nums1.size()],top=0;
    stack[top]=nums1[0];
    for(int forward=1;forward<nums1.size();forward++)
    {
        if(stack[top]<nums1[forward] and top>-1)
        {
            int diff=0;
            while(stack[top]<nums2[forward] and top>-1)
            {
                ++diff;
                --top;
            }
            int el=nums1[forward];
            for(int i=0;i<nums2.size();i++) 
            {
                if(nums2[i]==el)
                {
                    res[forward-diff]=i;
                    break;
                }
            }   
        }
        else stack[++top]=nums1[forward];
    }
    return res;
}

int main()
{
    std::vector<int> a={4,1,2};
    std::vector<int> b={1,2,3,4};
    std::cout<<nextGreaterElement(a,b);
}