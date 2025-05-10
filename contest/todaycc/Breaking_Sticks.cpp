#include <iostream>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(--t>-1)
    {
        int n ;
        cin>>n;
        int possible=0;
        for(int i =0;i<n;i++)
        {
            int c;
            cin>>c;
            possible+=(c-1);
        }        
        cout<<possible<<'\n';
    }
}
