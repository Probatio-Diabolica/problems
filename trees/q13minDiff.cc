#include"includes.hpp"


int getMinimumDifference(TreeNode* root) {
    int minDiff=100000, prev=100000;

    TreeNode* curr=root;

    while(curr)
    {
        if(curr->left)
        {
            TreeNode* leftChild= curr->left;
            while(leftChild->right)
            {
                leftChild = leftChild->right;
            }

            leftChild->right= curr;
            TreeNode* node = curr;
            curr=curr->left;
            node->left=0;

        }
        else{
            int x= std::abs(prev - curr->val);
            minDiff = (minDiff < x) ?  minDiff : x ;
            prev=curr->val;
            curr=curr->right;
        }
    }
    return minDiff;
}


int main()
{
    TreeNode* tree;
    std::vector<int> a={1,1,2000,300,4000,5000,60,700,800,900};
    tree=sortedArrayToBST(a);

    std::cout<<getMinimumDifference(tree);
}



void morrisTraversal(TreeNode* node)
{
    TreeNode* curr=node;
    while(curr)
    {
        if(curr->left)
        {
            TreeNode* leftChild=curr->left;
            
            while(leftChild->right) leftChild=leftChild->right;
            
            leftChild->right=curr;
            TreeNode* temp = curr->left;
            curr=curr->left;
            temp->right=0;

            leftChild->right= curr;
            TreeNode* node = curr->left;
            curr=curr->left;
            node->right=0;

        }else
        {
            std::cout<<curr->val;
            curr=curr->right;
        }
    }
}