#include<iostream>
#include<vector>

// #ifdef __cplusplus
//     void version(){
//         std::cout<<__cplusplus;
//     }
// #endif


void swap(int& a, int& b)
{
    int temp=a;a=b;b=temp;
}

void mix(std::vector<int> &nums)
{
    int head=0,tail=nums.size()-1;
    while (head<=tail-1)
    {
        swap(nums[head],nums[head+1]);
        head+=2;
    }    
}



void  print(const std::vector<int> &nums) 
{
    std::cout<<"array=> ";
    for(const int& a: nums)
    {
        std::cout<<a<<" ";
    }
    std::cout<<std::endl;
}



int main(int argc,char **argv)
{
    std::vector<int> numsA={1,2,3,4,5};
    std::vector<int> numsB={1,2,3,4,5,8};
    std::vector<int> numsC={1,2,3,4,5,99};
    std::vector<int> numsD={1,2};
    int arr[5]={1,4,5,6,7};
    std::cout<<"Test case A"<<std::endl;
    print(numsA);
    mix(numsA);
    print(numsA);
    std::cout<<"Test case B"<<std::endl;
    print(numsB);
    mix(numsB);
    print(numsB);
    std::cout<<"Test case C"<<std::endl;
    print(numsC);
    mix(numsC);
    print(numsC);
    std::cout<<"Test case D"<<std::endl;
    print(numsD);
    mix(numsD);
    print(numsD);

    
    std::cout<<"\n"<<__cplusplus;
    //version();
    return 0;
    
}