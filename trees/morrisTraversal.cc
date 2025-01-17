#include"includes.hpp"

std::vector<int> morrisComplexIT(TreeNode* root)
{
    std::vector<int> sol={};
    TreeNode* curr=root;
    while(curr)
    {
        if(curr->left)
        {
            TreeNode* leftChild=curr->left;
            while(leftChild->right and leftChild->right!=curr)
            {
                leftChild=leftChild->right;
            }
            if(leftChild->right)
            {
                leftChild->right=0;
                sol.push_back(curr->val);
                curr=curr->right;
            }else{
                leftChild->right=curr;
                curr=curr->left;
            }
        }
        else
        {
            sol.push_back(curr->val);
            curr=curr->right;
        }
    }
    return sol;
}

std::vector<int> mT_simple_inorderTraversal(TreeNode* root) 
{
    std::vector<int> sol={};
    TreeNode* curr=root;
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
            TreeNode* temp=curr;
            curr=curr->left;
            temp->left=0;
        }
        else
        {
            sol.push_back(curr->val);
            curr=curr->right;
        }
    }
    return sol;
}

int main()
{
    std::vector<int> a={0,1,2,3,4,5,6,7,8};
    TreeNode* node;
    node= sortedArrayToBST(a);
    std::cout<<node;
    std::vector<int> ab= mT_simple_inorderTraversal(node);
    std::cout<<ab[0];
}



