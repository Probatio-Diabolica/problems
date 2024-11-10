#include"includes.hpp"

int minDepth_BFS(TreeNode* root) 
{
    if(!root) return 0;
    std::queue<TreeNode*> q;
    q.push(root);
    int depth=1;

    while(!q.empty())
    {
        int n=q.size();
        while(n--)
        {
            TreeNode* temp= q.front();
            q.pop();
            if(!temp->left and !temp->right) return depth;

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        ++depth;
    }
    return -1;
}

int minDepth(TreeNode* root) 
{
    if(!root) return 0;

    if(!root->left and !root->right) return 1;

    int left= minDepth(root->left);
    int right= minDepth(root->right);
    return ((left>right) ? right :  left)+1;
}


int main()
{
    std::vector<int> vec={1,2};
    TreeNode* node = sortedArrayToBST(vec);
    std::cout<<minDepth_BFS(node);
}