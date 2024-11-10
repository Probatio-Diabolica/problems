#include"includes.hpp"

void dfs(TreeNode* root, int &sum,bool left)
{
    if(!root) return;
    //// we are setting the eft switches to be true 
    dfs(root->left,sum,true);
    dfs(root->right,sum,false);
    //!! Main condition : if it is a leaf node and it is left leaf, then sum it baby
    if(!root->left and !root->right and left) sum+= (root->val); 
} 

int sumOfLeftLeaves(TreeNode* root) {
    int sum=0;
    dfs(root,sum,false);
    return sum;
}

int main()
{
    
    std::vector<int> a={1,2,3,4,5,4,3};
    TreeNode* node=makeTree(0,a.size()-1,a);
    std::cout<<node<<"\n";
    std::cout<<sumOfLeftLeaves(node);
}