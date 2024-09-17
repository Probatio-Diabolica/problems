/*
*  Q: given an array find the sum of its subarray of size 3. using sliding window.

-> 2,3,5,2,9,7

*/

#include<iostream>
#include<vector>


void return_Max_Sum(std::vector<int> &array,int k)
{
    if(k<=array.size())
    {

        int sum=array[0],max=0;
        for(int i=1;i<=k;i++)
        {
            sum+=array[i];
        }
        max=sum;
        for(size_t curr=1;curr<array.size()-k+1;curr++)
        {
            sum+= array[curr+k-1]-array[curr-1];
            if(sum>max) max=sum;
        } 

        std::cout<<"Max : "<< max<<"\n";
    }
    else
    {
        std::cout<<"error\n";
    }
}


int main()
{
    std::vector<int> vec={2,3,5,2,9,7,8,0,8,9,1};
    std::vector<int> vec2={2,3,5,2,9,8,9,1};
    std::vector<int> vec3={2,3,0,8,9,1};
    std::vector<int> vec4={2,3,5,2,9,7,8,1};
    std::vector<int> vec5={2,3,5,0,8,9,1};
    return_Max_Sum(vec,4);
    return_Max_Sum(vec2,4);
    return_Max_Sum(vec3,4);
    return_Max_Sum(vec4,4);
    return_Max_Sum(vec5,4);
}