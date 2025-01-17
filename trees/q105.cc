#include"includes.hpp"

TreeNode* solve(std::vector<int>& preorder, std::vector<int>& inorder,int start,int end,int& idx)
{
    if(start> end) return nullptr;
    int rootVal=preorder[idx];
    int i= start;
    for(;i<=end;i++)
    {
        if(inorder[i]==rootVal) break;
    }
    ++idx;
    TreeNode* root=new TreeNode(rootVal);
    root->left=solve(preorder,inorder,start,i-1,idx);
    root->right=solve(preorder,inorder,i+1,end,idx);
    return root;
}

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) 
{
    int n=preorder.size();
    int idx=0;
    return solve(preorder,inorder,0,n-1,idx);
}

int main()
{

}