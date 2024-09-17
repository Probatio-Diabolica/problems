#include<iostream>

struct vec3
{
    float x,y,z;
    void operator+=(vec3& v)
    {
        x+=v.x;
        y+=v.y;
        z+=v.z;
        // return *this;
    }
};

int main()
{
    vec3 a={1,2,3};
    vec3 b={2,3,4};
    a+=b;
    std::cout<<a.x <<" "<< a.y;
}