#include<iostream>
#include<vector>
int numOfSubarrays(std::vector<int>& arr, int k, int threshold) 
{
    int netSubs=0,sum=0;
    for(short int i=0;i<k;i++)
    {
        sum+=arr[i];
    }
    if (float(sum/k) >= float(threshold)) netSubs++;

    for(size_t i=1;i<=(arr.size() -k);i++)
    {
        sum+=arr[i+k-1] - arr[i-1];
        if (float(sum/k) >= float(threshold)) netSubs++;
    }
    return netSubs;
}

int main()
{
    std::vector<int> a={2,2,2,2,5,5,5,8};
    std::cout<<numOfSubarrays(a,3,4);
    // , k = 3, threshold = 4
}