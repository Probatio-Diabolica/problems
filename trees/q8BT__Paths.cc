#include"includes.hpp"

void dfs(TreeNode* node,std::string str,std::vector<std::string>& vec)
{
    // if(!node) return ;
    std::string cp= str+"->"+std::to_string(node->val);
    
    if((!node->left )and (!node->right))
    {
        vec.push_back(str);
        return ;
    } 
    
    if(node->left) dfs(node->left,cp,vec);
    if(node->right) dfs(node->right,cp,vec);
}

std::vector<std::string> binaryTreePaths(TreeNode* root) 
{
    std::vector<std::string> sol={};
    if(!root) return sol;

    std::string temp=std::to_string(root->val);
    if((!root->left )and (!root->right)) sol.push_back(temp);
    if(root->left) dfs(root->left,temp,sol);
    if(root->right) dfs(root->right,temp,sol);
    return sol; 
}
std::ostream& operator <<(std::ostream& stream, std::vector<std::string> & vec)
{
    for(std::string s:vec) stream<<s<<" , ";
    stream<<"\n";
    return stream;
}

int main()
{
    std::vector<int> a={1,2,3,4,5,6,7,8,9,99,88,77,66,55,44,33,22,11};
    TreeNode* node= makeTree(0,a.size()-1,a);
    // std::cout<<node;
    std::vector<std::string> ans= binaryTreePaths(node);
    std::cout<<ans;

    delete node;
}