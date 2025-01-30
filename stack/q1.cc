#include<bits/stdc++.h>
bool isValid(std::string s)
{
    std::stack<char> st;
    std::unordered_map<char,char> map;
    map[')']='(';
    map['}']='{';
    map[']']='[';

    for(char a:s)
    {
        if(map.contains(a))
        {
            if(st.size()>0 and st.top()==map[a]) st.pop();
            else return false;
            
        }else st.push(a);
    }
    return (st.size()>0) ? false : true;

}

int main()
{
    __cplusplus;
    std::string a="]";
    std::cout<<isValid(a);
}