#include<string>
#include<iostream>

int maxConsecutiveAnswers(std::string answerKey, int k) 
{
    int maxWindowLen=0,right=0;
    for(int left=0;i<=answerKey.size()-maxWindowLen;i++)
    {
        int currentWindowLen=1;
        int allowence=k;
        right=left;
        while( currentWindowLen >=maxWindowLen and right<answerKey.size() )
        {
            
        }
        maxWindowLen = maxWindowLen >currentWindowLen ? maxWindowLen : currentWindowLen;
    }
    return window;
}

int main()
{

}