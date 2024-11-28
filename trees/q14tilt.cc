#include"includes.hpp"

int dfs(TreeNode* node)
{
    if(!node) return 0;

    int left=dfs(node->left);
    int right=dfs(node->right);

    node->val= (left ==0 and right ==0) ? node->val :  std::abs(left-right);
    return node->val;
}


int findTilt(TreeNode* root) 
{
    return dfs(root);
}


int main()
{
    TreeNode* node;
    std::vector<int> arr={1,2,3,4,5,6,7,8};
    node=sortedArrayToBST(arr);
    int tilt=findTilt(node);
    std::cout<<tilt;
}