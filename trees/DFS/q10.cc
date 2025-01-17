#include"includes.hpp"
#include<unordered_map>




void dfs(TreeNode* node,std::unordered_map<int,int> &map)
{
    if(!node) return;
    ++map[node->val];
    dfs(node->left,map);
    dfs(node->right,map);
}

std::vector<int> findMode(TreeNode* root) {
    std::unordered_map<int,int> map;
    std::vector<int> sol;
    dfs(root,map);
    int maxFreq=0;
    for(const auto &p:map)
    {
        if(p.second > maxFreq) 
        {
            maxFreq=p.second;
            // if(sol.size()==0)sol.push_back(p.first);
            // if(p.second > maxFreq)sol.clear();
            sol.push_back(p.first);
        }
        
        // std::cout<<"ran\n"; 
    }
    
    return sol;
}


int main()
{
    std::vector<int> vec={8,9,6,5,7,8,9,8,0,0,1},v;
    TreeNode* node;
    node=makeTree(0,vec.size()-1,vec);
    std::cout<<node<<"\n";
    v=findMode(node);
    std::cout<<v;
}