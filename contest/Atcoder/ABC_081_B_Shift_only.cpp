#include<iostream>
using namespace std;
int main()
{
    int N,m;
    cin>>N;
    int arr[N];
    m=N;
    for(int i=0;N>0;N-- , i++)
    {
        cin>>arr[i];
    }

    int res=0;
    while(true)
    {
        for(int i=0;i<m;i++)
        {
            if(arr[i]&1) 
            {
                std::cout<<res;
                return 0;
            }
            arr[i]/=2;
        }
        ++res;
    }

}