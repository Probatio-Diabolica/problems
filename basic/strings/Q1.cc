#include<iostream>
#include<string>


void swap(char *a,char* b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}

void reverse_string(std::string &s)
{
    int head=0,tail=s.length()-1;
    //ye harkate cool dikhne ke liye interview me mat krna verna pachtaoge.
    while(head<tail) swap(&s[head++],&s[tail--]);
}

std::string addStrings(std::string num1,std::string num2) 
{
    int carry=0,tail=(num1.length()>num2.length()) ? num1.length():num2.length(),diff= abs(num1.length()-num2.length());
    std::string result="";
    while((--tail)>-1)
    {
        int temp;
        if(num1.length()>num2.length()) 
        {   
            if((tail-diff)>-1) temp=(num1[tail]-'0' + num2[tail-diff]-'0') + carry;
            else temp=(num1[tail]-'0') + carry;
        }
        else
        {
            if((tail-diff)>-1) temp=(num1[tail-diff]-'0' + num2[tail]-'0') + carry;
            else temp=num2[tail]-'0' + carry;
        }
        carry=temp/10;
        temp%=10;
        std::string t=std::to_string(temp);
        result+=t;
    }
    if(carry>0) 
    {
        std::string t=std::to_string(carry);
        result+=t;
    }
    reverse_string(result);
    return result;        
}

int main()
{
    std::pair<std::string,std::string> a={"1230","123"};
    std::pair<std::string,std::string> b={"456","77"};
    std::pair<std::string,std::string> c={"1","9"};
    std::pair<std::string,std::string> d={"11","123"};
    
    std::cout<<addStrings(a.first,a.second)<<"\n";
    // std::cout<<addStrings(b.first,b.second)<<"\n";
    // std::cout<<addStrings(c.first,c.second)<<"\n";
    // std::cout<<addStrings(d.first,d.second)<<"\n";
    // std::cout<<x;
}