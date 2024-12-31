#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool checkIfExist(const vector<int>& arr) {
    unordered_map<int , int> mp;
    for(int i=0;i<arr.size();i++)
    {
        ++mp[arr[i]];
    }

    for(int i=0;i<arr.size();i++)
    {
        if(mp[2*arr[i]]>0) return true;
    }
    return false;
}

int main()
{   
    std::cout<<checkIfExist({10,2,5,3})<<"\n";
    std::cout<<checkIfExist({3,1,7,11})<<"\n";

}
