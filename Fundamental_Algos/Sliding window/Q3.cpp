#include<iostream>
#include<vector>

void minimumNumber(std::vector<int> &vec, int block)
{
    int min,current=vec[0],window=block-1;
    for(size_t i =1;i<block;i++) 
    {
        current-=vec[i];
    }
    min=current;
    for(size_t i=1;i<vec.size()-block+1;i++)
    {
        current-=vec[block+1]+vec[i-1];
    }
    std::cout<<"Minimum : "<<min<<"\n";
}

int main()
{   
    std::vector<int> vec={2,3,5,2,9,7,8,0,8,9,1};
    std::vector<int> vec2={2,3,5,2,9,8,9,1};
    std::vector<int> vec3={2,3,0,8,9,1};
    std::vector<int> vec4={2,3,5,2,9,7,8,1};
    std::vector<int> vec5={2,3,5,0,8,9,1};
    minimumNumber(vec,1);
    minimumNumber(vec2,4);
    minimumNumber(vec3,4);
    minimumNumber(vec4,4);
    minimumNumber(vec5,4);
}