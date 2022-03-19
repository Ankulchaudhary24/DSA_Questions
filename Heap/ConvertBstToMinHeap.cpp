/*

You are given a 'ROOT' of a binary search tree of integers. The given BST is also a complete binary tree.
Your task is to convert the given binary search tree into a Min Heap and print the preorder traversal of the updated binary search tree.

Sample Input 1:
1
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
10 7 11 1 8 -1 -1 -1 -1 -1 -1 
Sample Output 1:
2 5 6 7 8 10
1 7 8 10 11

*/

void inorder(BinaryTreeNode* &root, vector<int> &in)
{
    if(root == NULL)
        return;
    
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
    
}

void preorderFill(BinaryTreeNode* &root, int &i, vector<int>& in)
{
    if(root == NULL)
        return;
    if(i>=in.size())
        return;
    root->data = in[i++];
    preorderFill(root->left,i,in);
    preorderFill(root->right, i, in);
    
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
    int index =0;
	  vector<int> in;
    inorder(root, in);
    preorderFill(root,index,in);
    return root;
}
