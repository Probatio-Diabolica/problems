#include<iostream>

class A
{
private:
    int a =10;

protected:
    int x=1010;
    int getPROtectedValue()
    {
        return a;
    }
public:
    int aghs=90;
    A(int xaxa =10000)
    {
        a=xaxa;
    }
    void tetete()
    {
        std::cout<<"test";
    }
};

class B:A
{
private:
    
public:
    B(int abcs=9876)
    {
        x=abcs;
    }
    void getvalueee()
    {
        std::cout<<getPROtectedValue();
        std::cout<<aghs;
    }
};

// class test
// {
// private:
//     int xyz;
// public:
//     test(A a=A(767546))
//     {
//         xyz=a.getPROtectedValue();
//     }
//     void getValuessssss()
//     {
//         std::cout<<xyz;
//     }
// };
int main()
{
    B b=B();
    b.getvalueee();
    b.tetete();
    
}