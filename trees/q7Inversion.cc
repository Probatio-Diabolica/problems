#include"includes.hpp"

void swap(TreeNode* node)
{
    TreeNode* temp=node->left;
    node->left=node->right;
    node->right=temp;
}
void inversion(TreeNode* root)
{
    if(!root) return;
    swap(root);
    inversion(root->left);
    inversion(root->right);
}

TreeNode* invertTree(TreeNode* root) {
    if(!root) return root;
    inversion(root);
    return root;
}

int main()
{
    TreeNode* node;
    std::vector<int> a={0x90,0x89,0xFF,0x9F,0x6A,0x7B,0x56F};
    node=makeTree(0,a.size()-1,a);
    std::cout<<"BEFORE :: "<<node<<"\n";
    inversion(node);
    std::cout<<"AFTER ::  "<<node;
    delete node;
}