#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(--t>-1)
    {
        int n;
        cin>>n;
        vector<long long> x(n);
        unordered_map<long long, int> mp;
        for(int i=0;i<n;i++)
        {
            long long y;
            cin>>y;
            x[i]=y;
            ++mp[y];
        }
        bool check = false;
        for(int i =0;i<n ; i++)
        {
            for(int j = (n==1) ? i : i+1;j<n;j++)
            {
                if(mp[x[i]+x[j]]==0)
                {
                    check= true;
                    cout<<x[i]<<' '<<x[j]<<'\n';
                    i=n,j=n;
                }
            }
        }
        if(!check) cout<<-1<<'\n';
    }
}
