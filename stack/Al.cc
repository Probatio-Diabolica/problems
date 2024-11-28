#include<iostream>
#include<vector>
std::ostream& operator<<(std::ostream & stream,std::vector<int> vec)
{
    for ( int i: vec) stream<<i<<" ";
    return stream;
}

std::vector<int> diff(std::vector<int> &vec)
{
    static std::vector<int> res(vec.size());
    int stack[vec.size()],top=0;
    stack[0]=vec[0];
    for(int forward=1;forward<vec.size();forward++)
    {
        if(top>-1 and stack[top]<vec[forward])
        {
            int diff=0;
            for(int backward=forward;stack[top]<vec[forward] and top>-1;backward--)
            {
                res[backward-1]=++diff;
                --top;
            }
        }
        if(stack[top]>vec[forward]) stack[++top]=vec[forward];
    }
    return res;
}

int main()
{
    std::vector<int> a={0,0,0,0,0,0,0};

    std::cout<<diff(a);
}