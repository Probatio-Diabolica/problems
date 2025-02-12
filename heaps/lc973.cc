#include"includes.hpp"
#include<cmath>

float distance(iArray& x)
{
    float sol =  sqrt((x[0]-0)*(x[0]-0) + (x[1]-0)*(x[1]-0));
    return sol;
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    auto cmp = [](iArray& x, iArray &y){
        return (distance(x)>distance(y));
    };
    std::priority_queue<std::vector<int>,iMat,decltype(cmp)> pq;   

    for(int i = 0 ; i<points.size();i++)
    {
        pq.push(points[i]);
    }

    iMat sol(k);
    for(int i=0;i<k;i++)
    {
        sol[i]= pq.top();
        pq.pop();
    }
    return sol;
}


int main()
{
    iMat x = {{3,3},{5,-1},{-2,4}};
    std::cout<<kClosest(x,2);
}