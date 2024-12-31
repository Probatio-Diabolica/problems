#include"include.hpp"





int candy(const vector<int>& ratings) {
    int n=ratings.size();
    vector< int> res(ratings.size(),1);
    for(int i=1;i<n;i++)
    {
        if(ratings[i]>ratings[i-1]) res[i]=res[i-1]+1;
    }

    for(int i=n-2;i>-1;i--)
    {
        if(ratings[i]>ratings[i+1]) res[i]=max(res[i],res[i+1]+1);
    }
    int sol=0;
    for(int i=0;i<n;i++)
    {
        sol+=res[i];
    }
    return sol;
}


int main()
{
    cout<<"\n"<<candy({1,0,2});
    cout<<"\n"<<candy({1,2,2});
}