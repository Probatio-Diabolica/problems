#include"includes.hpp"


int work(int left,iArray &states)
{
    if(left == 0) return 1;
    if(states[left]!=-1) 
    {
        return states[left];
    }
    int ways= work(left-1,states);
    if(left>=2) ways += work(left-2,states);
    return  states[left] = ways;
}

int climbStairs(int n) {
    std::vector<int> states(n+5,-1);
    int ways = work(n,states);
    return ways;
}


int climbstairsTab(int n)
{
    if(n<=3) return n;
    std::vector<int> states(n+1,0);
    states[1]=1,states[2]=2,states[3]=3;
    for(int i = 3 ;i<=n;i++)
    {
        states[i]=states[i-1]+states[i-2];
    }
    return states[n];
}

int climbstairsBest(int n)
{
    if(n<=3) return n;
    int a =1, b=2 ,c=3;
    for(int i =3;i<=n;i++)
    {
        c=a + b;
        a=b;
        b=c;
    }
    return c;
}
int main()
{
    cout<<climbstairsBest(3)<<" || "<<climbstairsBest(45);
}
