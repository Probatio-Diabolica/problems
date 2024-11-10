#include<iostream>

bool is_a_car(char a)
{
    if(a>='a' and a<='z') return true;
    else if(a>='A' and a<='Z') return true;
    else if(a>='0' and a<='9') return true; 
    return false;
}

bool isPalindrome(std::string s) 
    {
        int start=0, end=s.size()-1;
        while(start<=end){
        if(!is_a_car(s[start]) or !is_a_car(s[end]))
        {
            if(!is_a_car(s[start])) ++start;
            if(!is_a_car(s[end])) --end;
            continue;
        }
        else
        {
            if((s[start]==s[end])or ((s[start]>='a' and s[start]<='z') and s[start]-'a'==s[end]-'A') or (((s[end]>='a' and s[end]<='z'))and s[end]-'a'==s[start]-'A')) 
            {
                ++start;
                --end;
            }
            else{
                return false;
            }
        }
       }
       return true;     
    }

int main()
{
    std::string a="0P";
    std::cout<<isPalindrome(a);
    // std::cout<<is_a_car('!');
}