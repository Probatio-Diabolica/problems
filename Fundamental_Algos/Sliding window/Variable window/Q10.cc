#include<iostream>
#include<string>

/*
!! unoptimized
int numberOfSubstrings(std::string s)
{
    int possibilites=0;
    for(size_t left=0;left<=s.length()-3;left++)
    {
        bool a=false,b=false,c=false;
        size_t right=left+1;
        switch (s[left])
            {
            case 'a':
                a=true;
                break;
            
            case 'b':
                b=true;
                break;

            default:
                c=true;
                break;
            }

        while((right<s.length())and !(a and b and c))
        {
            switch (s[right])
            {
            case 'a':
                a=true;
                break;
            
            case 'b':
                b=true;
                break;

            default:
                c=true;
                break;
            }

            if(a and b and c) possibilites++;
            ++right;
        }
        possibilites += ((s.length()) - right);
    }
    return possibilites;
}
*/

int min(int a,int b ,int c)
{
    return (a<b)&&(a<c) ? a : (b<c) ? b : c ; 
}

int numberOfSubstrings(std::string s)
{
    int count=0,container[3]={-1,-1,-1};

    for(size_t i=0;i<s.length();i++)
    {
        container[s[i]-'a']=i;
        count+= (1 + min(container[0],container[1],container[2])); 
    }
    return count;
}
int main()
{
    std::string a="abcabc";
    std::string b= "aaacb";
    std::cout<<numberOfSubstrings(a)<<"\n";
    std::cout<<numberOfSubstrings(b);
    // std::cout<<numberOfSubstrings(a);

}