#include"includes.hpp"


vector<int> leaders(vector<int>& arr) {
    std::vector<int> res={};
    int watch=arr.size()-1;
    for(int i =watch;i>-1;i--)
    {
        if(arr[i]>=arr[watch])
        {
            res.push_back(arr[i]);
            watch=i;
        }
    }
    return res;
}


int main()
{
    std::vector<int> a={16, 17, 4, 3, 5, 2};
    std::vector<int> b={10, 4, 2, 4, 1};

    std::cout<<leaders(a)<<'\n';
    std::cout<<leaders(b)<<std::endl;
}