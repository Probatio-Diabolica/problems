#include<iostream>
#include<vector>
using namespace std;
bool range(string a,int current,int l,int r)
{
    return (a[current]>l and a[current]<r) ? true : false;
}

bool palindrome(string s,int head,int tail)
{
    if(head<tail)
    {
        if(s[head]==s[tail]) palindrome(s,++head,--tail);
        else
        {
            if(s[head]<90 and s[head]>40)
            {
                if(s[tail]<124 and s[tail]>96)
                {
                    int diff=s[tail]-'a';
                    if((s[head]-diff)==(s[tail]-diff)) palindrome(s,++head,--tail);
                    else return false;
                }
            }
            else if(s[head]<124 and s[head]>96)
            {
                if(s[tail]<90 and s[tail]>40)
                {
                    int diff=s[head]-'a';
                    if((s[tail]-diff)==(s[head]-diff)) palindrome(s,++head,--tail);
                    else return false;
                }
            }
            else if(!(range(s,head,40,90)) or !(range(s,head,96,124))) palindrome(s,++head,tail);
            else if(!(range(s,tail,40,90) )or !(range(s,tail,96,124))) palindrome(s,head,--tail);
        }   
        
    }
    else return true;
}
bool isPalindrome(string s) 
{
        return palindrome(s,0,s.size()-1);
}
int main()
{
    // unsigned long int a= 234;

    // unsigned long int &ofA=a; //takes the reference
    // std::cout<<sizeof(&ofA)<<" "<<sizeof(a);
    std::string a="aba";
    std::cout<<isPalindrome(a);
}


// https://github.com/sebastianstarke/OCR
