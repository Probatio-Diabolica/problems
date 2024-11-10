# pragma once
#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* makeTree(int l,int r,std::vector<int> &nums)
{
    if(l>r) return nullptr;
    int mid = l+ (r-l)/2;
    TreeNode* root=new TreeNode(nums[mid]);
    root->left=makeTree(l,mid-1,nums);
    root->right=makeTree(mid+1,r,nums);
    return root;
}

TreeNode *sortedArrayToBST(std::vector<int> &nums)
{
    return makeTree(0,nums.size()-1,nums); 
}

std::ostream &operator<<(std::ostream & stream, TreeNode* node)
{
    //note: preorder only
    TreeNode* temp=node;
    if(temp)
    {
        stream<<temp->val <<" , ";
        stream<<temp->left;
        stream<<temp->right;
    }
    return stream;
}

