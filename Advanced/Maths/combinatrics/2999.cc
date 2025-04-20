#include <cmath>
#include<iostream>
#include<string>


long long combi(std::string& endStr,std::string& suffix , int lim)
{

    if(endStr.length() < suffix.length()) return 0;
    long long sol = 0;
    //starting elements which I can manipulate
    std::string manipulate = endStr.substr(endStr.length() - suffix.length());

    int lenLeft = endStr.length() - suffix.length();

    for(int i = 0 ; i <lenLeft ; i++)
    {
        int digit = endStr[i]-'0';
        if(digit <= lim ) sol+=digit * std::pow(lim+1,lenLeft-i-1);
        else{
            sol+= std::pow(lim+1,lenLeft-i);
            return sol;
        }
    }

    if(manipulate >= suffix) ++sol;
    return sol;
}

long long numberOfPowerfulInt(long long start, long long finish, int limit, std::string s) {
        std::string startStr = std::to_string(start-1);
        std::string finishStr = std::to_string(finish);
        
        return combi(finishStr,s,limit ) - combi(startStr,s,limit);
}

int main()
{

}