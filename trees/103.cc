#include"includes.hpp"

void reverse(std::vector<int>& v)
{
    for(int i=0;i<v.size()/2;i++)
    {
        std::swap(v[i],v[v.size()-1 - i]);
    }
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    std::vector<std::vector<int>> result{};
    std::queue<TreeNode*> q;
    int lvl = 1;
    if(root) q.push(root);
    while(!q.empty())
    {
        
        int n = q.size();
        vector<int> v{};
        while(n>0)
        {
            TreeNode* curr = q.front();
            q.pop();
            v.emplace_back(curr->val);
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
            --n;
        }
        if(lvl&1)reverse(v);
        result.push_back(v);
        ++lvl;
    }
    return result;
}


int main()
{

}