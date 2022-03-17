/*

Given a Binary Search Tree, modify the given BST such that itis balanced and has minimum possible height.

Examples :

Input:
       30
      /
     20
    /
   10
Output:
     20
   /   \
 10     30

Input:
         4
        /
       3
      /
     2
    /
   1
Output:
      3            3           2
    /  \         /  \        /  \
   1    4   OR  2    4  OR  1    3   OR ..
    \          /                   \
     2        1                     4 

*/

void inorder(Node* root, vector<int>& in)
{
    if(root == NULL)
    {
        return ;
    }
    
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
    
}

Node* buildTree(vector<int> in, int s, int e)
{
    if(s>e)
    return NULL;
    
    int mid = (s+e)/2;
    Node* root = new Node(in[mid]);
    root->left = buildTree(in,s,mid-1);
    root->right = buildTree(in,mid+1,e);
    return root;
}

Node* buildBalancedTree(Node* root)
{
    vector<int> in;
    inorder(root, in);
    
    return buildTree(in,0,in.size()-1);
}
