#include<iostream>
#include<vector>


void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) 
{

}

int main(int argc, char const **argv)
{
    std::vector<int> a={1,2,3,4};
    auto it=a.begin();
    a.insert(it+2,40);
    while(it!=a.end())
    {
        std::cout<<*it<<"\n";
        ++it;
    }
    std::cout<<'j'<<a[0];
}
