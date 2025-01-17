#include"includes.hpp"


bool symmetry(std::vector<int> & vec)
{
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i]!=vec[(vec.size()-1)-i]) return false;
    }
    return true;
}



bool isSymmetric(TreeNode* root) 
{
        TreeNode* itr=root;
        bool result=true;
        std::queue<TreeNode*> q;
        q.push(itr);
        while(!q.empty())
        {
            int size = q.size();
            std::vector<int> level;
            for(int i=0;i<size;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                level.push_back(temp->val);
            }

            result = symmetry(level);
        }
        return result;
}

int main()
{
    std::vector<int> a={1,2,3,4,3,1,1};
    std::cout<<symmetry(a);
}