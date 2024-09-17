
#include<iostream>
#include<vector>

int numberOfAlternatingGroups(std::vector<int>& colors)
{
        int groups=0;
        if( (colors[0]!=colors[colors.size()-1]) && (colors[0]!=colors[1]) ) groups++;
        for(short int i=1;i<colors.size()-1;i++)
        {
            if( (colors[i]!=colors[i+1]) && (colors[i]!=colors[i-1]) ) groups++;
        }
        if( (colors[0]!=colors[colors.size()-1]) && (colors[colors.size()-1]!=colors[colors.size()-2]) ) groups++;
        return groups;
}

int numberOfAlternatingGroups2(std::vector<int>& colors) //optimized
{
        int groups=0;
        if(colors[1]==colors[colors.size()-1] ) 
        {
            if(colors[0]!=colors[1])
            groups++;
        }
        for(short int i=1;i<colors.size()-1;i++)
        {
            if(colors[i+1]==colors[i-1] )
            {
                if(colors[i]!=colors[i-1] ) groups++;
            }
        }
        if(colors[0]==colors[colors.size()-2] ) 
        {
            if(colors[0]!=colors[colors.size()-1])
            groups++;
        }
        return groups;
}
int main()
{
    std::vector<int> vec    = {1,1,1,1};
    std::vector<int> vec2   = {0,1,0,0,1};
    std::vector<int> vec3   = {1,0,1,0,1,0,1,1,1,0};
    std::vector<int> vec4   = {1,0,1,1,1,0,0,1,0,0,0,1,0,1,0};
    std::cout<<numberOfAlternatingGroups2(vec)<<"\n";
    std::cout<<numberOfAlternatingGroups2(vec2)<<"\n";
    std::cout<<numberOfAlternatingGroups2(vec3)<<"\n";
    std::cout<<numberOfAlternatingGroups2(vec4)<<"\n";
}