#include<iostream>
#include<unordered_map>

bool isHappy(int n) 
{
    std::unordered_map<int,int> mp;
    ++mp[n];
    bool cycle=true;
    while(cycle)
    {
        int ans=0;
        while(n>=1)
        {
            ans+=(n%10)*(n%10);
            n/=10;
        }
        if(ans==1) return true;
        if(mp[ans] >1) cycle =false;
        mp[ans]++;
        n=ans;
    }   
    return cycle;     
}

int main()
{
    int num[4]={19,2,32,64};
    for(int i=0;i<4;i++)
    {
        std::cout<<isHappy(num[i])<<"\n";
    }
}