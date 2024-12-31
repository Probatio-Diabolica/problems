#include"include.hpp"

int canCompleteCircuit(const vector<int>& gas,const vector<int>& cost) {
    int n=gas.size();
    int netGas=0,currentGas=0;
    int start=0;
    for(int i=0;i<n;i++)
    {
        int fuel =gas[i] - cost[i];
        netGas+=fuel;
        currentGas+=fuel;
        if(currentGas<0)
        {
            currentGas=0;
            start = i+1;
        }
    }
    
    return netGas<0 ? -1 : start;
}

int main()
{

    cout<<canCompleteCircuit({1,2,3,4,5},{3,4,5,1,2})<<"\n";

    //bad solution here
    cout<<canCompleteCircuit({2,3,4},{3,4,3})<<"\n";

    cout<<canCompleteCircuit({2},{2})<<"\n";

    cout<<canCompleteCircuit({3,1,1},{1,2,2})<<"\n";

    cout<<canCompleteCircuit({5, 1, 2, 3, 4},{4, 4, 1, 5, 1})<<"\n";

}