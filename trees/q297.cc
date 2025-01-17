#include"includes.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
using namespace std;

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str="";
        deque<TreeNode*> dq;
        if(!root) return "";
        dq.push_back(root);
        while(dq.size()>0){
            int n=dq.size();
            for(int e=0;e<n;e++){
                TreeNode* treeNode=dq.front();
                dq.pop_front();
                int num=(treeNode==NULL)?1001:treeNode->val;
                if(num!=1001){
                    if(treeNode->left){
                        dq.push_back(treeNode->left);
                    }else{
                        dq.push_back(NULL);
                    }
                    if(treeNode->right){
                        dq.push_back(treeNode->right);
                    }else{
                        dq.push_back(NULL);
                    }
                }
                str+=to_string(num);
                str+=",";
            }
        }
        str=str.substr(0,str.size()-1);
        // cout<<str<<endl;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;
        int n=data.size();
        int e=0;
        queue<int> q;
        queue<TreeNode*> treeQ;
        while(e<n){
            string str="";
            while(e<n && data[e]!=','){
                str+=data[e];
                e++;
            }
            q.push(stoi(str));
            e++;
        }
        TreeNode *root=new TreeNode(q.front());
        q.pop();
        treeQ.push(root);
        while(!q.empty()){
            TreeNode *temp=treeQ.front();
            treeQ.pop();
            if(!q.empty()){
                int left=q.front();
                q.pop();
                if(left!=1001){
                    temp->left=new TreeNode(left);
                    treeQ.push(temp->left);
                }
            }
            if(!q.empty()){
                int right=q.front();
                q.pop();
                if(right!=1001){
                    temp->right=new TreeNode(right);
                    treeQ.push(temp->right);
                }
            }
        }
        return root;
    }

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));



int main()
{
    TreeNode* node;
    vector<int> s={1,2,3,4,5,7,9};
    node=sortedArrayToBST(s);
    string sol=serialize(node);
    cout<<sol;
}