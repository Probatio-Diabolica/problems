#include"includes.hpp"


std::vector<int> rightSideView(TreeNode* root)
{
    std::vector<int> ans={};
    std::queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        std::vector<int> level_arr;
        for(int i=0;i<size;i++)
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            level_arr.push_back(temp->val);
        }
        ans.push_back(level_arr[level_arr.size()-1]);
    }
    return ans;
}

int main()
{
    std::vector<int> vec{1,2,3,4,5,6,7,8};
    TreeNode* root; 
    root=sortedArrayToBST(vec);
    // std::cout<<root;
    std::vector<int> sol=rightSideView(root);
    std::cout<<sol;
    // 1,2,3,4,5,6,7,8
    // int x=8 + (1+7) + (6+2) + (5+3) + (4);

}

