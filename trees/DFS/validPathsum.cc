#include"includes.hpp"

void dfs(TreeNode* root, int cSum,int tSum,bool& result)
{
    if(!root or result) return ;
    // if(result) return;
    cSum+=root->val;
    if(!root->left and !root->right) result= (cSum==tSum);

    dfs(root->left,cSum,tSum,result);
    dfs(root->right,cSum,tSum,result);
}

bool hasPathSum(TreeNode* root, int targetSum) 
{
    bool result=false;
    int cSum=0;
    dfs(root,cSum,targetSum,result);
    return result;
}



int main()
{
        std::vector<int> vec={1,2,3,4,5,6,7,8,9};
    TreeNode* node = sortedArrayToBST(vec);
    std::cout<<hasPathSum(node,8);
}