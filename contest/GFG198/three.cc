#include "include.hpp"
#include <string>

// vector<int> minOperation(string& s, vector<vector<int>>& Q) {
//     // code here
//     std::vector<int> sol(Q.size());
//     for(int i = 0 ; i<Q.size() ;i++)
//     {
//         int effort=0;
//         int vowels[5]{0,0,0,0,0};
//         int r=Q[i][1];
//         for(int l=Q[i][0];l<r+1;l++)
//         {
//             if(s[l]=='a') ++vowels[0];
//             else if(s[l]=='e') ++vowels[1];
//             else if(s[l]=='i') ++vowels[2];
//             else if(s[l]=='o') ++vowels[3];
//             else if(s[l]=='u') ++vowels[4];
//         }
//         int maxi=0,sum=0;
//         for(int i = 0;i<5;i++)
//         {
//             if(vowels[i] > maxi) maxi=vowels[i];
//             sum+=vowels[i];
//         }
//         effort=(maxi* 5 ) - sum;
//         sol[i]= effort;
//     }
//     return sol;
// }

vector<int> minOperation(string& s, vector<vector<int>>& Q) {
    // code here
    std::vector<int> sol(Q.size());
    for(int i = 0 ; i<Q.size() ;i++)
    {
        int vowels[5]{0,0,0,0,0};
        int r=Q[i][1];
        for(int l=Q[i][0];l<r+1;l++)
        {
            if(s[l]=='a') ++vowels[0];
            else if(s[l]=='e') ++vowels[1];
            else if(s[l]=='i') ++vowels[2];
            else if(s[l]=='o') ++vowels[3];
            else if(s[l]=='u') ++vowels[4];
        }
        int maxi=0,sum=0;
        for(int i = 0;i<5;i++)
        {
            if(vowels[i] > maxi) maxi=vowels[i];
            sum+=vowels[i];
        }
        sol[i]= (maxi* 5 ) - sum;
    }
    return sol;
}

int main()
{
    vector<iArray> vec{{2,4},{0,4}};
    string s ="aeexu";
    std::cout<<minOperation(s, vec);
}