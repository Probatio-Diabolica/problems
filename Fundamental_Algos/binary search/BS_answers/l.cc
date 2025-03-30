#include <climits>
#include <iostream>
#include<vector>

int bCOUNT(std::vector<int>& bloomDay, int day, int k)
{
    int bCount = 0;
    for(int i = 0 , adCount =0;i < bloomDay.size();i++)
    {
        if(bloomDay[i] <=day) ++adCount;
        else adCount=0; 
        
        if(adCount == k)
        {
            ++bCount;
            adCount=0;
        }
    }
    return bCount;
}

int minDays(std::vector<int>& bloomDay, int m, int k) 
{
    int n = bloomDay.size();
    int start=INT_MAX,end=INT_MIN;    
    for(int i : bloomDay)
    {
        if(end < i) end =i;
        if(i < start) start = i; 
    }

    int midDay = -1;
    while(start <= end)
    {
        int mid = start + (end-start)/2;
        if(bCOUNT(bloomDay, mid, k) >= m)
        {
         midDay=mid;
         end = midDay-1;
        }
        else start = mid+1; 
        
    }
    return midDay;
}

int main()
{

}