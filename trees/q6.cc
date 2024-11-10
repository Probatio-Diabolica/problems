#include"includes.hpp"

int getEXP(int num,int power)
{
    int res=1;
    while(power>0)
    {
        if(power&1) res*=num;
        num*=num;
        power>>=1;
    }
    return res;
}

int getLH(TreeNode* root)
{
    TreeNode* temp=root;
    int height=0;
    while(temp)
    {
        temp=temp->left;
        ++height;        
    } 
    return height;
}

int getRH(TreeNode* root)
{
    TreeNode* temp=root;
    int height=0;
    while(temp)
    {
        temp=temp->right;
        ++height;        
    } 
    return height;
}

int countNodes(TreeNode* root)
{
    if (!root) return 0;

    int LH= getLH(root);
    int RH= getRH(root);

    if(LH==RH) return getEXP(2,LH) -1;

    return countNodes(root->left) + countNodes(root->right) +1;
}

int countNodes__ON(TreeNode* root) 
{
    if(!root) return 0;
    int nodes=0;
    std::queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                nodes++;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
    }
    return nodes;
}

int main()
{
    std::vector<int> a={0x90,0x38,0x26,0x94,8,0,2,0x78,0x12};

    TreeNode* node=makeTree(0,a.size()-1,a);
    std::cout<<countNodes(node);
}