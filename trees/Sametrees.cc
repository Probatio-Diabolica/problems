#include"includes.hpp"
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// The two trees are said to be equal if and only if they return the same values upon traversals.
//// We can either do this by picking up any traversal way we want.
//// After that what we can do is :
//* store the value in an array  and compare.
// WARN: this has a very bad complexity as the only time will be O(2N) in the worst case.
//!!Something better is the check the values during traversal and at anythime , we see a different value we return False, else we return true   
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool inorder(TreeNode* p,TreeNode* q, int strenght)
{
    if(p and q)
    {
        if(p->val != q->val)  strenght*=0;
        inorder(p->left,q->left,strenght);
        inorder(p->right,q->right,strenght);
    };
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    return inorder(p,q,1);
}