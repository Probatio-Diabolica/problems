#include <iostream>
using namespace std;

int main() {
	int cases;
    cin>>cases;
    int n,x;
    int out;
    while(cases>0)
    {
        cin >> n >> x;
        int r= n%6;
        out = (r==0) ? n/6 : (n/6)+1;
        cout<< out* x<<"\n";
        --cases;
    }

}