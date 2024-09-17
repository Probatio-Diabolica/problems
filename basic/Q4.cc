#include<iostream>
int evenlyDivides(int N){
        int digit=0,num=N;

        while(num>0)
        {
            int a=(num%10);
            num/=10;
            if(a!=0) if(N%a==0) digit++;
        }
        return digit;
}

int main()
{
    std::cout<<evenlyDivides(22074)<<"\n";
}