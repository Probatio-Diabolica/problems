#include<iostream>

class A
{
public:
    int a;
    A()
    {
        a=100;
    }
    int getA() const
    {
        return a;
    }
};


int main()
{
    //!! valid
    //// A *x= new A[10];
    //// for(int i=0;i<10;i++)
    //// {
    ////     std::cout<<x[i].getA()<<"\n";
    //// }
    //// delete[] x;

    //!! valid
    //// A* x= new A();
    //// x->getA();
    ////   std::cout<<x->getA()<<"\n";
    //// delete x;
}