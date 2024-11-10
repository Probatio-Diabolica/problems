#include"includes.hpp"



    int mostFreqent(int arr[26])
    {
        int maxval=0;
        for(int i=0;i<26;i++)
        {
            if(arr[i]>maxval) maxval=arr[i];
        }
        return maxval;
    }

    int characterReplacement(string s, int k) 
    {
        int freq[26]={};
        int left =0,winSize=0;

        for(int right=0;right<s.size();right++)
        {
            //$ Expansion towards right
            ++freq[s[right] - 'A' ];
            
            if( (right-left+1)-mostFreqent(freq) <=k ) winSize = (right-left+1);
            else
            {
                //$ shrink from left 
                --freq[s[left++]-'A'];
                if( (right-left+1)-mostFreqent(freq) <=k ) winSize = (right-left+1);
            }

        }
        return winSize;

    }


int main()
{
    string a="ABABBA";
    std::cout<<characterReplacement(a,2);
}