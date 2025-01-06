
#include"includes.hpp"
std::ostream& operator<<(std::ostream& stream , std::vector<std::vector<int>> &vec)
{
    for(int i=0;i<vec.size();i++)
    {
         stream<<"level "<<i+1<<" : ";
        for(int j=0;j<vec.size();j++)
        {
            stream<<vec[i][j]<<" ";
        }
        stream<<"\n";
    }
    return stream;
}


std::ostream& operator<<(std::ostream& stream , std::vector<int> &vec)
{

    for(int j=0;j<vec.size();j++)
    {
        stream<<vec[j]<<" ";
    }
    stream<<"\n";
    
    return stream;
}


template<typename type>
struct Node{
    type data;
    Node<type>* left;
    Node<type>* right;

    Node(type info,Node<type>* left, Node<type>* right)
    {
        data=info;
        this->left=left;
        this->right=right;
    }  

    Node(type info)
    {
        data=info;
        this->left=nullptr;
        this->right=nullptr;
    }
};

template<typename type>
std::ostream& operator<<(std::ostream& stream , Node<type>* node )
{
    stream<<node->data<<"\n";
    return stream;
}

template<typename type>
void preorder(Node<type>* node)
{
    if(node)
    {
        std::cout<<node;
        preorder(node->left);
        preorder(node->right);
    }
} 

template<typename type>
void postorder(Node<type>* node)
{
    if(node)
    {
        preorder(node->left);
        preorder(node->right);
        std::cout<<node;
    }
}


template<typename type>
void inorder(Node<type>* node)
{
    if(node)
    {
        inorder(node->left);
        std::cout<<node;
        inorder(node->right);   
    }
}

template<typename type>
Node<type>* array_to_tree(std::vector<type>& vec)
{
    Node<type>* head= new Node<type>(vec[0]),*temp=head;
    for(int i=1;i<vec.size();i++)
    {
        if(!temp->left)temp->left=new Node<type>(vec[i]);
        else if(! temp->right) temp->right=new Node<type>(vec[i]);
        else 
        {
            temp=temp->left;
            temp->left=new Node<type>(vec[i]);
        }
    }
    return head;
}

template<typename type>
std::vector<std::vector<int>> bfs(Node<type>* head)
{

    std::vector<std::vector<int>> ans;
    std::queue<Node<type>*> q;
    q.push(head);
    while(!q.empty())
    {
        int size = q.size();
        std::vector<int> level;
        for(int i=0;i<size;i++)
        {
            Node<type>* temp=q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            level.push_back(temp->data);
        }
        ans.push_back(level);
    }
    return ans;
}   


template<typename type>
int maxDepth(Node<type> *root)
{
    if(!root) return 0;
    int Left = maxDepth(root->left);
    int Right= maxDepth(root->right);
    return  ((Left>Right) ? Left+1 : Right+1);
}

template<typename type>
void pre_postT(Node<type>* node,std::vector<int> &vec)
{
    if(!node) return;
    Node<type>* temp=node;
    std::stack<Node<type>*> stack;
    stack.push(temp);
    while(!stack.empty())
    {

        // pre order
        //--------------------------------
        temp=stack.top();
        stack.pop();
        vec.push_back(temp->data);
        //-----------------------



        if(temp->right) stack.push(temp->right);
        if(temp->left) stack.push(temp->left);


        //// post order
        //// --------------------------------
        //// temp=stack.top();
        //// stack.pop();
        //// vec.push_back(temp->data);
        //// -----------------------
    }
}


template<typename type>
std::vector<int> inorderT(Node<type>* root)
{
    std::stack<Node<type>*> stack;
    std::vector<int> sol={};
    Node<type>* temp=root;
    while(true)
    {
        if(temp)
        {
            stack.push(temp);
            temp=temp->left;
        }
        else
        {
            if(stack.empty()) break;
            temp=stack.top();
            stack.pop();
            sol.push_back(temp->data);
            temp=temp->right;

        }
    }
    return sol;
}

int main()
{
    Node<int>* tree;
    std::vector<int> vec={7,8,9,5,6,3,3,4,6,1},sol={};
    // // std::cout<<tree;
    tree=array_to_tree(vec);
    std::vector<std::vector<int>> output=bfs(tree);
    std::cout<<output;
    // preorder(tree);
    // std::cout<<"---------------------------------\n";
    // std::cout<<"Depth : "<<maxDepth(tree)<<"\n";
    // postorder(tree);
    // std::cout<<"---------------------------------\n";
    inorder(tree);
    // pre_postT(tree,sol);
    sol=inorderT(tree);
    std::cout<<"\n"<<sol;
    delete tree;
    std::cout<<"Sayuz nerushimy respublik svabodhnikh\n";
}