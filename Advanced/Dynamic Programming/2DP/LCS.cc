#include"includes.hpp"


int work(int a, int b ,string& x, string& y,std::vector<std::vector<int>>& states)
{
    if(a<0 or b<0) return 0;
    if(states[a][b]!=-1) return states[a][b];
    auto max = [](int a , int b) {
        return a> b ? a: b;
    };
    
    int solution = work(a-1,b,x,y,states);

    solution = max(solution,work(a,b-1,x,y,states));

    solution = max(solution,work(a-1,b-1,x,y,states)+ (x[a]==y[b]) );

    return states[a][b]=solution;
}


int longestCommonSubsequence(string text1, string text2) {
    std::vector<std::vector<int>> states(text1.size()+10,(std::vector<int>(text2.length()+10,-1)));
    return work(text1.length()-1,text2.length()-1,text1,text2,states);
}

int main()
{
    string A="acbsdfghjcvbnghyuj",B="yuihjkhjkhjkabc";
    cout<<longestCommonSubsequence(A,B);
}