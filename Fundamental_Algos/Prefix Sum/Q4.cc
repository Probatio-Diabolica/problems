#include"includes.hpp"
//brute
int sumOddLengthSubarrays_brute(std::vector<int>& arr) 
{
    int sum=0;
    if(arr.size()==1) return arr[0];
    else if(arr.size()==2) return arr[0]+arr[1];
    std::vector<int> sr(arr.size(),0);
    for(int i=0;i<arr.size();i++) 
    {
        sum+=arr[i];
        sr[i]=sum;
    }  
    
    for(int i=0;i<(arr.size()-2);i++)
    {
        for(int j=i+2;j<arr.size();j+=2)
        {
            // if((j-i+1)%2==1) sum+=(sr[j]- ((i==0) ? 0 : sr[i-1]));
            sum+=(sr[j]- ((i==0) ? 0 : sr[i-1])); //if(i==0 then subtract by zero else subtract by i-1th pos 
        }
    }
    return sum;
}

//best 
int sumOddLengthSubarrays(std::vector<int>& arr) 
{
    int res = 0, n = arr.size();
    for (int i = 0; i < n; ++i) {
        res += ((i + 1) * (n - i) + 1) / 2 * arr[i];
    }
    return res;
}
int main()
{
    std::vector<int> a={1,2,3,4};
    std::cout<<sumOddLengthSubarrays(a);
}