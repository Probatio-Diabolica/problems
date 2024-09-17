#include<iostream>

void maxVowels(std::string &str,int block)
{
    int max=0;
    int num=0,window=block-1;
    for(int i=0;i<block;i++)
    {
        if(str[i]=='a' ||str[i]=='e' ||str[i]=='i' ||str[i]=='o' ||str[i]=='u' ) num ++;
    }
    max=num;
    for(size_t i =1;i<str.size()-block+1;i++)
    {
        if(str[i-1]=='a' ||str[i-1]=='e' ||str[i-1]=='i' ||str[i-1]=='o' ||str[i-1]=='u' ) num --;
        if(str[i+window]=='a' ||str[i+window]=='e' ||str[i+window]=='i' ||str[i+window]=='o' ||str[i+window]=='u' ) num++;
        if(max<num) max=num;
    }

    std::cout<<"Max vowels : "<<max<<"\n";
}

int main()
{
    std::string test="cygejknyw";
    std::string test2="hfnivewuhvwkvbk";
    std::string test3="vuwengskgrsnk";
    std::string test4="fhnvnakgfak";
    std::string test5="vhfwlveiuqnhufaklhagl";
    maxVowels(test,4);
    maxVowels(test2,4);
    maxVowels(test3,4);
    maxVowels(test4,4);
    maxVowels(test5,4);
}