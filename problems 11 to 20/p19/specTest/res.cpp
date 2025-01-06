#include "t.h"
#include<string>
using std::string;


//note: DO NOT USE THIS INSIDE A HEADER FILE AT AT POINT.



int maint(int argc, char ** argv)
{
    A a(100,100);
    a.printARR();
    string x="hallo! tie und milch bitte";
    std::cout<<x;
    return 0;
}