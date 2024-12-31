#include <bits/stdc++.h>
using namespace std;

bool solve(float a,float b, float c)
{
    return ((a+b)/2) > c;
}

int main() {
	int cases;
    float a,b,c;
    cin>>cases;
    while(cases>0)
    {
        cin>> a>>b>>c;
        (solve(a,b,c)) ? cout<<"YES\n":cout<<"NO\n";
        --cases; 
    }

}


