/*

A string is good if there are no repeated characters.

Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.

Note that if there are multiple occurrences of the same substring, every occurrence should be counted.

A substring is a contiguous sequence of characters in a string.

-------------------------------------------------------------------------------------------------------------
//Example 1:

Input: s = "xyzzaz"
Output: 1
Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
The only good substring of length 3 is "xyz".

// Example 2:

Input: s = "aababcabc"
Output: 4
Explanation: There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
The good substrings are "abc", "bca", "cab", and "abc".

-----------------------------------------------------------------------------------------------------------------
// Constraints:

    1 <= s.length <= 100
    s​​​​​​ consists of lowercase English letters.


*/

#include<iostream>

int countGoodSubstrings(std::string s) 
{
    short int handler=0;
    for(short int i=1;i<s.size()-1;i++)
    {
        if( (s[i]!=s[i-1])  &&  (s[i+1]!=s[i])  &&  (s[i+1]!=s[i-1])    ) handler++;
    }
    return handler;
}

int main()
{
    std::string str="xyzzaz";
    std::string str2="aababcabc";
    std::string str3="gdhgfdhasjfbmdc";
    std::string str4="gdhsvdbsnavfdghasgshfaghs";
    std::string str5="sadadasjhdbhasjdashdvaassa";
    std::cout<<countGoodSubstrings(str)<<"\n";
    std::cout<<countGoodSubstrings(str2)<<"\n";
    std::cout<<countGoodSubstrings(str3)<<"\n";
    std::cout<<countGoodSubstrings(str4)<<"\n";
    std::cout<<countGoodSubstrings(str4)<<"\n";
    std::cout<<countGoodSubstrings(str5)<<"\n";
}