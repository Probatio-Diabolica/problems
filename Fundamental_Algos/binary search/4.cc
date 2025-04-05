#include<iostream>
#include <vector>


double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();

    // Elements and their location
    int idxA = (n+m)/2 , idxB = idxA -1;
    int elA = -1, elB=-1;
    //

    int i = 0, j = 0,k =0;

    while(i < n and j < m)
    {
        if(nums1[i] > nums2[j])
        {
            if(k == idxA) elA = nums2[j];
            if(k == idxB) elB = nums2[j];
            ++j;
        }
        else
        {
            if(k == idxA) elA = nums1[i];
            if(k == idxB) elB = nums1[i];
            ++i;
        }
        ++k;
    }

    while( i<n)
    {
        if(k == idxA) elA = nums1[i];
        if(k == idxB) elB = nums1[i];
        ++i;
        ++k;
    }
    while(j < m)
    {
        if(k == idxA) elA = nums2[j];
        if(k == idxB) elB = nums2[j];
        ++j;
        ++k;
    }

    if((n+m)&1) return elA;
    return (elA + elB)/2.00 ;
}


int main()
{

}