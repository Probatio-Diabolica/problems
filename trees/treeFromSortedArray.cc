#include"includes.hpp"
// TreeNode* makeTree(int l,int r,std::vector<int> &nums)
// {
//     if(l>r) return nullptr;
//     int mid = l+ (r-l)/2;
//     TreeNode* root=new TreeNode(nums[mid]);
//     root->left=makeTree(l,mid-1,nums);
//     root->right=makeTree(mid+1,r,nums);
//     return root;
// }

// TreeNode* sortedArrayToBST(std::vector<int>& nums) {
//     return makeTree(0,nums.size()-1,nums); 
// }

void preOrder(TreeNode* root)
{
    if(root)
    {
        std::cout<<root->val <<" , ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    std::vector<int> a={1,2,3,4,5};
    TreeNode* root= makeTree(0,a.size()-1,a);
    a.push_back(root->val);
    preOrder(root);
}