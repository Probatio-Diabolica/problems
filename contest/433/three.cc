#include"include.hpp"

long long mini(long long a, long long b)
{
    return (a < b) ? a : b;
}
long long mini(long long a,long long  b, long long c)
{
    return (a<b and a< c) ? a: (b > c) ? c : b;
}

long long DFS(vector<vector<int>>& cost,int choice,int hno,std::vector<std::vector<int>>& states)
{
    if(hno > cost.size()-1) return 0;
    if(states[hno][choice] != -1) return states[hno][choice];
    long long solution=0;
    if(choice == 0)
    {
        solution=mini(DFS(cost,1,hno+1,states),DFS(cost,2,hno+1,states)) + cost[hno][choice];
    }
    else if(choice==1)
    {
        solution=mini(DFS(cost,0,hno+1,states),DFS(cost,2,hno+1,states)) + cost[hno][choice];
    }else
    {
        solution=mini(DFS(cost,1,hno+1,states),DFS(cost,0,hno+1,states)) + cost[hno][choice];
    }
    return states[hno][choice]=solution;
}


long long minCost(int n, vector<vector<int>>& cost) {
    vector<vector<int>> states(n,vector<int>(3,-1));
    return mini(DFS(cost,0,0,states) ,DFS(cost,1,0,states) ,DFS(cost,2,0,states));
}

int main()
{
    vector<iArray> a={{2,4,6},{5,3,8},{7,1,9},{4,6,2},{3,5,7},{8,2,4}};
    std::cout<<minCost(6,a);
}