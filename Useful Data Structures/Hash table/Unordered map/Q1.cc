#include<iostream>
#include<vector>
#include<unordered_map>

int maxFrequency(std::vector<int>& a)
{
    std::unordered_map<int,int> map;
    int maxFreq=0;
    int maxAns=0;
    for(int i=0;i<a.size();i++)
    {
        map[a[i]]++;
    }
    for(int i=0;i<a.size();i++)
    {
        if(maxFreq==map[a[i]])
        {
            maxAns=a[i];
            break;
        }
    }
    return maxAns;
}

int main(int argc, char const *argv[])
{
    std::vector<int>a={3,4,2,3,4,7};
    std::cout<<maxFrequency(a);
}
