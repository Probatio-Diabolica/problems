#include "includes.hpp"
#include <climits>
#include <unordered_map>

using col  = int;
using list = vector<int>;


void dfs(TreeNode* root, int &max, int &min, int currCol,int currRow, std::unordered_map<col,list> &map)
{
    // if(!root) return;
    // int l=-1,r=1;
    map[currCol].push_back(root->val);
    if(max<currCol) max = currCol;
    else if(min>currCol) min = currCol;

    if(root->left) dfs(root->left,max,min,currCol-1,currRow+1,map);
    if(root->right) dfs(root->right,max,min,currCol+1,currRow+1,map);
}


vector<vector<int>> verticalTraversal(TreeNode* root) {
    std::unordered_map<col,list> map;
    std::vector<list> sol;
    int max=0 , min=0;
    if(root)
    {
        dfs(root,max,min,0,0,map);
        for(int i=min;i<=max;i++)
        {
            if(!map[i].empty())sol.push_back(map[i]);
        }
    }
    return sol;
}

int main()
{

}