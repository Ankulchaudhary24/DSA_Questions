/*

You are given two balanced binary search trees of integers having ‘N’ and ‘M’ nodes.
You have to merge the two BSTs into a balanced binary search tree and return the root node to that balanced BST.

A binary search tree (BST) is a binary tree data structure with the following properties.
• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.

*/

void changeBSTToDLL(TreeNode<int> *root, TreeNode<int>* &head)
{
    if(root == NULL)
        return;
    changeBSTToDLL(root->right, head);
    
    root->right = head;
    if(head !=NULL)
        head->left = root;
    
    head = root;
    
    changeBSTToDLL(root->left, head);
}

TreeNode<int> *mergeLinkedList(TreeNode<int> * head1, TreeNode<int>* head2)
{
    TreeNode<int>* head = NULL;
    TreeNode<int>* tail = NULL;
    
    while(head1 != NULL && head2!= NULL)
    {
        if(head1->data < head2->data)
        {
            if(head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if(head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    
    while(head1 != NULL)
    {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
    }
    
    while(head2 != NULL)
    {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
    }
    return head;
}

int linkedSize(TreeNode<int> *root)
{
    int count =0;
    TreeNode<int> *head = root;
    while(head != NULL)
    {
        head = head->right;
        count++;
    }
    return count;
}

TreeNode<int>* convertLLtoBST(TreeNode<int>* &head, int n)
{
    if(n<=0 || head == NULL)
    {
        return NULL;
    }
    
    TreeNode<int>* left = convertLLtoBST(head, n/2);
    
    TreeNode<int>* root = head;
    root->left = left;
    head = head->right;
    
    root->right = convertLLtoBST(head, n-n/2-1);
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    TreeNode<int>* head1 = NULL;
    TreeNode<int> *head2 = NULL;
    changeBSTToDLL(root1, head1);
    changeBSTToDLL(root2, head2);
    head1->left = NULL;
    head2->left = NULL;
    
    TreeNode<int> * head = mergeLinkedList(head1,head2);
    int size = linkedSize(head);
    head =  convertLLtoBST(head, size);
    return head;
}