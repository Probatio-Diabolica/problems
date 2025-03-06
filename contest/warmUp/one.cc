#include<iostream>
#include<vector>

using iArray = std::vector<int>;

void dfs(int current, int limit, iArray& result)
{
    if(current>limit) return ;
    result.emplace_back(current);
    for(int i=0;i<=9;i++)
    {
        int newNum = (current*10 )+ i;
        if(newNum>limit) return ;
        dfs(newNum,limit,result);
    }
}

std::vector<int> lexicalOrder(int n) {
    iArray solution;
    for(int i=1;i<=9;i++)
    {
        if(i>n) return solution;
        dfs(i,n,solution);
    }
    return solution;
}


std::ostream & operator<<(std::ostream& stream, const iArray& arr);
int main()
{
    std::cout<<lexicalOrder(15);
}

std::ostream & operator<<(std::ostream& stream, const iArray& arr)
{
    for(int i=0;i<arr.size();i++)
    {
        stream<<arr[i]<< " ";
    }
    return stream;
}