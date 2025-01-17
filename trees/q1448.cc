#include"includes.hpp"

// // helper function
void dfs(TreeNode* root, int big, int& good)
{
    if(!root) return ;
    int prev;
    if(root->val >=big)
    {
        prev=big;
        big=root->val;
        ++good;
        
    }
    dfs(root->left,big,good);
    if(root->val==big)
    {
        big=prev;
    }
    dfs(root->right,big,good);
}

int goodNodes(TreeNode* root) {
    if(!root) return 0;
    int good=0,big=root->val;
    dfs(root,big,good);
    return good;
}




int main()
{
    std::vector<int> vec{1,2,3,4,5,6,7,8,9};
    TreeNode* node;
    node = sortedArrayToBST(vec);
    // std::cout<<node;
    std::cout<<goodNodes(node);
}

