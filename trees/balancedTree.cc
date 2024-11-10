#include"includes.hpp"


int dfsHeight(TreeNode* root)
{
    if(!root) return 0;
    int leftH = dfsHeight(root->left);
    if(leftH==-1) return -1;
    int rightH= dfsHeight(root->right);
    if(rightH==-1) return -1;
    if(abs(leftH-rightH) > 1) return -1;
    return max(leftH,rightH) +1;
}

bool isBalanced(TreeNode* root)
{
    return dfsHeight(root)!=-1;
}

int main()
{
    std::vector<int> vec={1,2,3,4,5,6,7,8,9};
    TreeNode* root=createBalancedTree(vec);
    return false;
}