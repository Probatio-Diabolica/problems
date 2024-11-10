
// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
std::ostream& operator<<(std::ostream& stream ,std::vector<int> arr)
{
    for(int i : arr) stream<< i <<" , ";
    return stream;
}

std::vector<int> findPNS(int lim)
{
    std::vector<int> res(lim,1),resPN;
    resPN.reserve(303);
    res[0]=0,res[1]=0;
    for(int i=2;i<lim;i++)
    {
        if (res[i]==1) 
        {   
            res[i]=i;
            resPN.push_back(i);
            for(int j=i*2;j<lim;j+=i)
            {
                res[j]=0;
            }
        }
    }
    return resPN;
}

int main()
{
    std::cout<<findPNS(2000);
}