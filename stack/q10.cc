#include "includes.hpp"

stack<int> insertAtBottom(stack<int> st,int x)
{
    int ashes=st.size();
    int arr[ashes];
    while(st.size()>0)
    {
        arr[st.size()-1]=st.top();
        st.pop();
    }

    st.push(x);

    for(int i=0;i<ashes;i++)
    {
        st.push(arr[i]);
    }
    return st;
}
stack<int> insertAtBottom2(stack<int> st,int x)
{
    stack<int> temp;
    while(st.size()>0)
    {
        temp.push(st.top());
        st.pop();
    }
    st.push(x);
     while(temp.size()>0)
    {
        st.push(temp.top());
        temp.pop();
    }
    return st;
}

void solve(stack<int>& st,int x)
{
    if(st.size()==0)
    {
        st.push(x);
        return;
    }

    int num = st.top();
    st.pop();
    solve(st,x);
    st.push(num);
}
stack<int> insertAtBottom3(stack<int> st,int x)
{
    //recursion
    solve(st,x);
    return st;
}
int main()
{
    stack<int> st;
    for(int i=0;i<6;i++)
    {
        st.push(i*21+2);
    }

    stack <int> res=insertAtBottom3(st,21);
    while(res.size()>0)
    {
        std::cout<<res.top()<<" sz :" <<res.size() <<" || \n";
        res.pop();
    }

    // std::cout<<__cplusplus;
}