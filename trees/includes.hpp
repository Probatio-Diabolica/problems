/*
!! notes :: There are two types of traversals :
$ BFS
$ DFS
@Probatio-Diabolica
@Hearn

*/

// # pragma once
#ifndef INCLUDES_HPP
#define INCLUDES_HPP
#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>


using namespace std;
using iArray = std::vector<int>;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// array must be sorted
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


std::ostream &operator<<(std::ostream & stream, const std::vector<int> &vec)
{
    for(int i=0;i<vec.size();i++)
    {
        stream<<vec[i] <<" , ";
    }
    return stream;
}

std::ostream &operator<<(std::ostream & stream, TreeNode* node)
{
    //note: preorder only
    // $ below was using recursion 
    // TreeNode* temp=node;
    // if(temp)
    // {
    //     stream<<temp->left;
    //     stream<<temp->val <<" , ";
    //     stream<<temp->right;
    // }

    //-> this one is using Morris traversal hence the TC: O(N), and SC : O(1)

    TreeNode* curr=node;
    stream<< "Inorder traversal :: \n";
    while (curr)
    {
        if(curr->left)
        {
            TreeNode* leftNODE = curr->left;
            while(leftNODE->right)
            {
                leftNODE=leftNODE->right;
            }
            
            //note: since  leftNode-> right does not exists, we make that pointer point to curr
            leftNODE->right=curr;

            //// let's make a ew pointer which will now point to this link 
            TreeNode* temp = curr;
            
            //!! let's go in the left direction of node. If left exists we will do all of the steps again else we will just return the current node's value 
            curr=curr->left;
            
            //!! just setting up the temp's left pointer to null
            temp->left=0;
        }
        else
        {
            stream<<curr->val <<" , ";
            curr=curr->right;
        }
    }
    
    // !! this can be converted into pre order as well
    return stream;
}


#endif