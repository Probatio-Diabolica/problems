#include<iostream>
#include<vector>
#include<unordered_map>

void solve(std::vector<int> &x)
{
    std::unordered_map<int,int> map;

    int checker=0;
    for(int i=0;i<4;i++)
    {
        ++map[x[i]];
        if(map[x[i]] > 1) ++checker;
    }
    
    (checker==2) ? std::cout<<  "Yes" : std::cout<< "No";
}


int main()
{
    std::vector<int> x(4,0);
    std::cin>>x[0]>>x[1]>>x[2]>>x[3];
    solve(x);

}