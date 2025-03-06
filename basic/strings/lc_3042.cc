#include"include.hpp"



bool isPrefixAndSuffix(string& word, string& bf)
{
    for(int i=0;i<bf.length();i++)
    {
        if(bf[i]!=word[i]) return false;
    }
    int it=word.length()-bf.length();
    for( int i=0;i<bf.length();i++)
    {
        if(word[i+it]!=bf[i]) return false;
    }

    return true;
}


int countPrefixSuffixPairs(vector<string>& words) {
    int solution =0;

    for(int i=0;i<words.size()-1;i++)
    {
        for(int j=i+1;j<words.size();j++)
        {

            if((words[i].length() <= words[j].length()) and isPrefixAndSuffix(words[j],words[i]))
            {
                ++solution;
            }
        }
    }

    return solution;
}



int main()
{
    vector<string> a={"abab","ab"};
    cout<<countPrefixSuffixPairs(a);
}