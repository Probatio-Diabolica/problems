#include"includes.hpp"



void dfs(TreeNode* root,std::vector<int>& vec)
{
    int currNUM=0,currFreq=0,maxFreq=0;
    TreeNode* curr=root;
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
            TreeNode*temp=curr;
            curr=curr->left;
            temp->left=0;
        }
        else
        {
            if(curr->val==currNUM)
            {
                ++currFreq;
            }else
            {
                currNUM=curr->val;
                currFreq=1;
            }
            if(currFreq>maxFreq)
            {
                vec={};
                maxFreq=currFreq;
            }
            if(currFreq==maxFreq) vec.push_back(curr->val);
            
            curr=curr->right;
        }
    }
}

void dfs(TreeNode* root,std::unordered_map<int,int>& map)
{
    TreeNode* curr=root;
    while (curr)
    {
        if(curr->left)
        {
            TreeNode* leftChild=curr->left;
            while(leftChild->right)
            {
                leftChild=leftChild->right;
            }
            leftChild->right=curr;
            
            //took temp so that I can delete the link next time
            TreeNode* temp=curr;
            //set the curr to the left part
            curr=curr->left;
            // freed the left link in the currect directory
            temp->left=0;
        }else
        {
            ++map[curr->val];
            curr=curr->right;
        }
    }
}
std::vector<int> findMode(TreeNode* root) 
{
    std::unordered_map<int,int> map;
    dfs(root,map);
    std::vector<int> result;
    int maxFreq=0;
    for(auto &it: map)
    {
        if(it.second > maxFreq)
        {
            maxFreq=it.second;
            result={};
            result.push_back(it.first);
        }else if(it.second == maxFreq) result.push_back(it.first);
    }

    return result;
}




std::vector<int> findModeBEST(TreeNode* root) 
{
    std::vector<int> result;
    dfs(root,result);

    return result;
}





int main()
{
    std::vector<int> vc={1,1,1,1,2,2,2,2,3,3,4,4,5,6,7};
    TreeNode* tree;
    tree=sortedArrayToBST(vc);
    std::cout<<findModeBEST(tree)<<'\n';
}