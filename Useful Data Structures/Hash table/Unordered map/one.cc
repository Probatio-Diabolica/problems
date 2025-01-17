#include<iostream>
#include<unordered_map>

int main()
{
    std::unordered_map<int,int> m;
    m[1]=1;
    m[1]=2;
    m[1]=3;
    m[1]=4;
    std::pair<int ,int> a={12,4};
    m.insert(a);
    std::cout<<m[1]<<"\n";
    std::cout<<m[12]<<" Size  "<<m.size()<<" finding\n";
    // for (int i=0;i<13;i++)
    // {
    //     std::cout<<m.count(i)<<"\n";
    // }
    std::cout<<"KEY  " <<"Entry\n";
    for (auto element:m)
    {
        std::cout<<element.first<<" , "<<element.second<<"\n";
    }

    //iterator
    std::unordered_map<int,int>::iterator it=m.begin();
    while(it!=m.end())
    {
        std::cout<<it->first << "   ,   "<<it->second<<"\n";
        ++it;
    }
}
