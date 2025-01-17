#include"includes.hpp"

void DFS(TreeNode* node, int k,int &smol)
{
    TreeNode* curr=node;
    int fact=0;
    while(curr)
    {
        if(curr->left)
        {
            TreeNode* leftChild=curr->left;
            while(leftChild->right)
            {
                leftChild=leftChild->right;
            }
            leftChild->right=curr;
            TreeNode* temp = curr;            
            curr=curr->left;
            temp->left=0;
        }
        else
        {
            ++fact;
            if(fact==k) 
            {
                smol=curr->val;
                return;
            }
            curr=curr->right;
        }
    }
}

int kthSmallest(TreeNode* root, int k) 
{
    int smol=0;
    DFS(root,k,smol);
    return smol;
}


int main()
{
    std::vector<int> a={1};
    TreeNode* node;
    node=sortedArrayToBST(a);
    std::cout<<kthSmallest(node,2);
}