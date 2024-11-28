#include"../includes.hpp"

typedef uint64_t big;
int widthOfBinaryTree(TreeNode* root) 
{
    std::queue<std::pair<TreeNode*,big>>  q;
    q.push({root,0});
    big maxWidth=0; 
    while(!q.empty())
    {
        big left=q.front().second;
        big right =q.back().second;

        if((right-left+1) > maxWidth) maxWidth=(right-left+1);
        int size=q.size();
        while(size--)
        {
            TreeNode* curr = q.front().first;
            big idx = q.front().second;
            q.pop();
            if(curr->left) q.push({curr->left,2*idx+1});
            if(curr->right) q.push({curr->right,2*idx+2});
        }
    }                                   

    return maxWidth;
}


int main()
{

}