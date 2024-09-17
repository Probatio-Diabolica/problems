#include<iostream>
#include<future>


void fun(int n)
{
    std::cout<<"Entered the func\n";
    if(n>0) 
    {
        std::cout<<n<<"\n";
        n--;
        fun(n);
    }else{
        
        
    } 
    
}

int main()
{
    int a=9;
    fun(a);
    std::cin.get();
}