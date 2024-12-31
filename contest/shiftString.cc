#include<iostream>
#include<vector>
using namespace std;

long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
    long long cost=0;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        int diff=0;
        int a=s[i] - t[i];
        int b=t[i] - s[i];
        diff=max(a,b);
        if(diff>13)
        {
            diff=(diff%13) +1;
            
        }
        else
        {

        }
        if(s[i]=='a') diff=0;
        else if(s[i]=='z') diff=25;

        if(diff>0) cost +=previousCost[i];
        else if(diff<0) cost += nextCost[diff*-1];  
    }
    return cost;
}


int main()
{

}