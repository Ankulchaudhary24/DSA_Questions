/*

You have been given a Binary Search Tree (BST). Your task is to flatten the given BST to a sorted list.
More formally, you have to make a right-skewed BST from the given BST, i.e.,
the left child of all the nodes must be NULL, and the value at the right child must be greater than the current node.
A binary search tree (BST), also called an ordered or sorted binary tree,
is a rooted binary tree whose internal nodes each store a value greater than all the values in the node's left subtree and less than those in its right subtree.

*/

void inorder(TreeNode<int>* root, vector<int >& in)
{
    if(root == NULL)
        return;
    
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> in;
    inorder(root, in);
    TreeNode<int>* head = new TreeNode<int>(in[0]);
    root = head;
    for(int i = 1;i<in.size();i++)
    {
        TreeNode<int>* temp = new TreeNode<int>(in[i]);
        root->right = temp;
        root = root->right;
    }

    return head;
}
