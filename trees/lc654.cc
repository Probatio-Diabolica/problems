#include"includes.hpp"

TreeNode* dfs(int l, int r, vector<int>& nums)
{
    if(l>r or r>=nums.size()) return nullptr;
    std::pair<int,int> info={0,l};
    for(int i=l;i<=r;i++)
    {
        if(info.first < nums[i]) 
        {
            info.first = nums[i];
            info.second = i;
        }
    }
    TreeNode* temp= new TreeNode(info.first);
    temp->left = dfs(l,info.second-1,nums);
    temp->right = dfs(info.second+1,r,nums);
    return temp;
}


TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return dfs(0,nums.size()-1,nums);
}

int main()
{
    iArray a={1,2,9,5,6,7};
    TreeNode* node = constructMaximumBinaryTree(a);
    std::cout<<node;
    delete node;
}