#include<iostream>
#include <vector>
using namespace std;

void fill(vector<vector<int>>sol,int lim)
{

    for(int i =0;i<sol.size();i++)
    {   
        for(int j=0;j<sol.size();j++)
        {
            sol[i][j] = lim
            
        }
    }
}

vector<vector<int>> specialGrid(int N) {
    vector<vector<int>> sol(1<<N);
    int lim = (1<<N)*(1 << N);
    fill(sol,lim-1);
    return sol;        
}

int main()
{
    specialGrid(4);
}