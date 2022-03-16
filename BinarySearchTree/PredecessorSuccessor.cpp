/*
There is BST given with root node with key part as integer only.
You need to find the inorder successor and predecessor of a given key.
In case, if the either of predecessor or successor is not found print -1.


*/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    if(root == NULL)
     return make_pair(-1,-1);
     
    int pre = -1;
    int suc = -1;
     BinaryTreeNode<int>* curr = root;
     while(curr->data != key)
    {
        if(curr -> data > key)
        {
            suc = curr->data;
            curr = curr -> left;
        }
        else
        {
            pre = curr->data;
            curr = curr -> right;
        }
    }
 
     BinaryTreeNode<int>* temp = curr->left;
     while(temp != NULL)
     {
       pre = temp->data;
       temp = temp->right;
     }
     
     
     temp = curr->right;
     while(temp != NULL)
     {
        suc = temp->data;
        temp = temp->left;
     }
    pair<int, int> ans ;
    ans.first = pre;
    ans.second = suc;
    return ans;
}
