#include<iostream>
#include<vector>
std::ostream& operator <<(std::ostream& stream, std::vector<std::string> vec)
{
    for(std::string a: vec) stream<< a<<" :: ";
    stream<<"\n";
    return stream;
}

void generate(std::vector<std::string>&valid,std::string &s,int open ,int close)
{
    if(open==0 and close==0)
    {
        valid.push_back(s);
        return ;
    }
    if(open>0)
    {
        s.push_back('(');
        generate(valid,s,open-1,close);
        s.pop_back();
    }
    if(close>0 and open<close)
    {
        s.push_back(')');
        generate(valid,s,open,close-1);
        s.pop_back();
    }
}

std::vector<std::string> generateParenthesis(int n) 
{
    std::string paran;
    std::vector<std::string> valid;
    generate(valid,paran,n,n);
    return valid;
}

int main()
{
    
    std::cout<<generateParenthesis(3);;
    // std::string a="ge";
    // std::cout<<a;
}