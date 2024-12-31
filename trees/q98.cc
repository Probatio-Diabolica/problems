#include"includes.hpp"
#define INT_MIN -1

// void dfs(TreeNode* node, std::vector<int>& sol)
// {
//     if(!node) return;
//     dfs(node->left,sol);
//     sol.push_back(node->val);
//     dfs(node->right,sol);
    
// }
// bool isValidBST(TreeNode* root) {
//     std::vector<int> sol;
//     dfs(root,sol);
//     bool res=true;
//     for(int i=1;i<sol.size() and res;i++)
//     {
//         if(sol[i]<=sol[i-1]) res=false;
//     }
//     return res; 
// }


// !! this solution signifies that I'm not good in dealing edge cases or put it simply, I'm not very good in considering all the possibilities

void MorrisInTraversal(TreeNode* node,bool &valid)
{
    TreeNode* curr=node;
    int64_t prev=INT64_MIN;
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
        else{
            if(prev >= curr->val and prev!=INT64_MIN) valid=false;
            prev=curr->val;
            curr=curr->right;
        }
    }
}

bool isValidBST(TreeNode* root) 
{
    if((!root->right) and (!root->left)) return true;
    bool valid=true;
    MorrisInTraversal(root,valid);
    return valid;
}

int main()
{
    std::vector<int> a={1,2,3,4,5,6,7,8},b={2,3,4,5,6,9,7,8,10,12};
    TreeNode* node,*node2;
    node=sortedArrayToBST(a);
    node2=sortedArrayToBST(b);
    std::cout<<isValidBST(node)<<"\n";
    std::cout<<isValidBST(node2);
}