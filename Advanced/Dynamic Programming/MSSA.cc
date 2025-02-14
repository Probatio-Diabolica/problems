#include"includes.hpp"


long long max(long long a , long long b)
{
    return a> b ? a : b;
}

long long max(long long a, long long b, long long c)
{
    return max(max(a,b),max(b,c));
}

long long DFS(int start, int end, vector<int>& nums)
{
    if(start > end) return 0;
    long long sola=0,solb=0,sol =0;
    int st=start;
    while(st <= end)
    {
        if(st&1) sola+=nums[st];
        else solb += nums[st];
        ++st;
    }
    sol=std::abs(sola-solb);
    sola = DFS(start+1,end,nums);
    solb = DFS(start,end-1,nums);

    return max(sol,sola,solb);
}

long long maxAlternatingSum(vector<int>& nums) {
    return DFS(0,nums.size()-1,nums);
}

int main()
{
    iArray x={6,2,1,2,4,5};
    std::cout<<maxAlternatingSum(x);

}