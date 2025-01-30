#include"include.hpp"

string __reverseWords(const string &s) {
    string solution;
    vector<string> sep;
    int r=0,l=0;
    for(int temp=0;temp<s.length();temp++)
    {
        if(s[temp] == ' ')
        {
            r=temp+1;
            l=temp+1;
        }else
        {
            r=temp;
            l=temp;
            temp=s.length();
        }

    }
    for(;r<s.length();r++)
    {
        if(s[r] == ' ')
        {
            string x=s.substr(l,r-l);
            if(x!="")             sep.push_back(x);
            l=r+1;
        }
    }
    sep.push_back(s.substr(l,r-l));
    cout<<sep.size()<<"\n";
    
    for(int i =sep.size()-1;i>-1;i--)
    {
        
        if(sep[i]!="")
        {
            solution+=sep[i];
            if(i>0) solution+=" ";
        }
    }
    return solution;
}


void swap(char& a, char& b)
{
    char temp=a;
    a=b;
    b=temp;
}

void reverse(string & s, int head, int tail)
{
    for(int i=head;i<(tail/2);i++)
    {
        swap(s[i],s[tail-i]);
    }
}

string reverseWords(string &s) 
{
    
    //swap once all
    reverse(s,0,)

    //for making correct words
    for(int l=0,r=1;r<s.size();r++)
    {
        if(s[r]==' ' and s[r-1]==' ')
        {
            for(int i=0;i<=r/2;i++)
            {
                swap(s[l],s[r-l]);
            }
            l=r+1;
        }
    }

    return s;
}


int main()
{
    std::string x="     a   car   ",y="blue is sky the",z="a good   example";
    cout<<reverseWords(x)<<"\n";
    cout<<reverseWords(y)<<"\n";
    cout<<reverseWords(z)<<"\n";
}