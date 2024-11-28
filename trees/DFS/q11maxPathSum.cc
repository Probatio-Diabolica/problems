#include"includes.hpp"

int max(int a,int b)
{
    return (a>b) ? a : b;
}
int max(int a,int b,int c)
{
    if(a>=b)
    {
        if(a>=c)
        {
            return a;
        }else{
            return c;
        }
    }
    else{
        if(a>=c)
        {
            return b;
        }else{
            if(b>=c) return b;
            else return c;
        }
    }
}
int dfs(TreeNode* root)
{
    if(!root) return 0;
    int l = dfs(root->left);
    int r= dfs(root->right);

    return max(root->val + max(l,r,0) , 0);
}
int maxPathSum(TreeNode* root) {
    return dfs(root->left) + dfs(root->right);
}

int main()
{
    std::vector<int> a= {1,2,3};
    TreeNode *node;
    node = makeTree(0,a.size()-1,a);
    std::cout<<node;
    std::cout<<dfs(node)<<"\n";

}