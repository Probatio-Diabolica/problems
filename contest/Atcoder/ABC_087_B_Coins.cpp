#include<iostream>
using namespace std;

int main()
{
    int fh,oh,fty,amt;
    cin>>fh>>oh>>fty>>amt;
    int res=0;
    for(int f100=0;f100<=fh;f100++)
    {
        for(int o100=0;o100<=oh;o100++)
        {
            for(int t50=0;t50<=fty;t50++)
            {
                int total=(f100*500)+(50*t50)+(100*o100);
                if(total==amt)
                {
                    ++res;
                }
                else if(total>amt)
                {
                    continue;
                }
            }
        }
    }

    std::cout<<res;

}