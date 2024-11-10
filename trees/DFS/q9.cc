#include"includes.hpp"

void dfs(TreeNode* root, int &sum,int currLeft)
{

    if(!root)
    {
        sum+=currLeft;
        return ;
    }
    if(root->left)
    {
        currLeft=root->left->val;
        dfs(root->left,sum,currLeft);
    }
    if(root->right) dfs(root->right,sum,currLeft);
} 
int sumOfLeftLeaves(TreeNode* root) {
    int sum=0;
    dfs(root,sum,0);
    return sum;
}

int main()
{
    
    std::vector<int> a={1,2,3,4,5};
    TreeNode* node=makeTree(0,a.size()-1,a);
    // std::cout<<node;
    std::cout<<sumOfLeftLeaves(node);
}