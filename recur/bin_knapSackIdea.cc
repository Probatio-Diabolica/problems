#include<bits/stdc++.h>
using namespace std;


void Sequence(int idx, vector<int>& v, int currSum, int sum , int arr[],int n)
{
    //we did something here
    //but what ?
    //first we checked out if idx == n
    if(idx == n)
    {
        //then we checked if currSum == sum 
        if(currSum==sum)
        {
            //yes : print all the sub sequence
            for(int i : v) cout<< i <<' ';
            cout<<'\n';
        }
        // else exit
        return;
    }

    //take the element
    v.push_back(arr[idx]);
    Sequence(idx+1,v,currSum+arr[idx],sum,arr,n);


    //don't take the element, instead move on
    v.pop_back(); //first we pushed , now we remove
    Sequence(idx+1,v,currSum,sum,arr,n);
}


int main()
{
    int arr[] = {1,2,3,4,5};
    int n = 5;
    int sum = 10;
    vector<int> ds;
    Sequence(0, ds, 0, sum,arr , n);
}