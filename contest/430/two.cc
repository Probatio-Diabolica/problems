#include<iostream>
#include<string>
using namespace std;
const string& max(const std::string& a, const std::string& b)
{
    int n=(a.length() < b.length()) ? a.length():b.length();
    for(int i=0;i< n;i++)
    {
        if(a[i]>b[i]) return a;
        if(b[i]>a[i]) return b;
    }
    return (a.length() < b.length()) ? b : a;
}
string answerString(const string& word, int numFriends) {

    if(numFriends==1) return word;
    int n=word.length();
    int maxlen=n-numFriends+1;
    string sol="";
    for(int i =0;i<n;i++)
    {

        string temp=word.substr(i,i+maxlen);
        sol=max(sol,temp);

    }
    return sol;
}
int main()
{
    std::cout<<answerString("dbca",2)<<"\n";
    std::cout<<answerString("gggg",4)<<"\n";
}