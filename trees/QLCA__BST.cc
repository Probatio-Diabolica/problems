#include "includes.hpp"


// TreeNode* somethin(TreeNode* node)
// {
//     if(!node)
// }

// TreeNode* search(TreeNode* root, TreeNode* p, TreeNode* q)
// {
//     if((root->val ==p->val) or (root->val== q->val)) return root;

//     TreeNode* node=nullptr;
//     if(root->left) node =search(root->left,p,q);
//     if(root->right) node =search(root->right,p,q);
//     return node;
// }

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{

    TreeNode* node=nullptr;
    if((root->val > p->val) and (root->val > q->val)  ) 
    {
        if(root->left) node=lowestCommonAncestor(root->left,p,q);
    } 
    else if((root->val < p->val) and (root->val < q->val)) 
    {
        if(root->right) node=lowestCommonAncestor(root->right,p,q);
    }
    else node = root;
    return node;
}



int main()
{
    std::vector<int> vec{0,1,2,3,4,5,6,7,8,9,10,11,12};
    TreeNode* root,*p=new TreeNode(7),*q=new TreeNode(1);

    root=sortedArrayToBST(vec);
    std::cout<<root->val<<std::endl;
    TreeNode* sol;
    sol=lowestCommonAncestor(root,p,q);
    std::cout<<sol->val;

}