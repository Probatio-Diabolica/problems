#include"includes.hpp"

void merge12(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    int last= m+n-1;
    while(m>0 and n>0)
    {
        if(nums1[m-1] > nums2[n-1])
        {
            nums1[last]=nums1[m-1];
            --m;
        }
        else
        {
            nums1[last]=nums2[n-1];
            --n;
        } 
        --last;
    }

    while(n>0)
    {
        nums1[last]=nums2[n-1];
        --n;
        --last;
    }
}
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    // what were are going to do is to make sure we go right to left
    int last= m+n-1;
    while(m>0 and n> 0)
    {
        if(nums1[m-1] > nums2[n-1])
        {
            nums1[last]=nums1[m-1];
            --m;
        }
        else
        {
            nums1[last]=nums2[n-1];
            --n;
        }
        --last;
    }
    while(n>0)
    {
        nums1[last]=nums2[n-1];
        --last;
        --n;
    }
}


int main()
{
    std::vector<int> a={4,5,6,0,0,0}, b={1,2,3} , c={1,2,3,0,0,0} , d={2,5,6};
    merge(a,3,b,3);
    std::cout<<a<<"\n";
    merge(c,3,d,3);
    std::cout<<c<<"\n";

}