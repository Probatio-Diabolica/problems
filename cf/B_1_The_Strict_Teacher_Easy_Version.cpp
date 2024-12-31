#include<iostream>
using namespace std;

int solve(int n,int tc[],int dc)
{
    int solution=0;
    bool david=true;
    int l=tc[0];
    int r=tc[1];
    while(david)
    {

        int go= std::abs(dc-l) > std::abs(dc-r) ? 1 : -1;

        //david moves
        if(dc>0 and dc<n-1)
        {
            
            
            ++dc;

            --dc;
        }




        if(std::abs(dc-l)==0 or std::abs(dc-r)==0)
        {
            david=false;
        }
    }
    return solution;
}


int main()
{
    int cases;
    cin>>cases;
    
    int n,m,q;
    

    while(cases>0)
    {
        cin>>n>>m>>q;
        int tc[2];
        cin>>tc[0];
        cin>>tc[1];

        int dc;
        cin>>dc;
        cout<<solve(n,tc,dc)<<"\n";
        --cases;
    }
}