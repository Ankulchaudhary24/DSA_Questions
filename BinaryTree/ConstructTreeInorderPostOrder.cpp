/*

Given inorder and postorder traversals of a Binary Tree in the arrays in[] and post[] respectively. The task is to construct the binary tree from these traversals.

 

Example 1:

Input:
N = 8
in[] = 4 8 2 5 1 6 3 7
post[] =8 4 5 2 6 7 3 1
Output: 1 2 4 8 5 3 6 7
Explanation: For the given postorder and
inorder traversal of tree the  resultant
binary tree will be
           1
       /      \
     2         3
   /  \      /  \
  4    5    6    7
   \
     8
 

Example 2:

Input:
N = 5
in[] = 9 5 2 3 4
post[] = 5 9 3 4 2
Output: 2 9 5 4 3
Explanation:  
the  resultant binary tree will be
           2
        /     \
       9       4
        \     /
         5   3
         
         */

int position(int in[], int ele, int size)
    {
        for(int i=0;i<size;i++)
        {
            if(in[i]==ele)
              return i;
        }
        return -1;
    }
    
    Node* solve(int in[], int post[], int &postOrderIndex, int inOrderStart, int inOrderEnd, int n)
    {
        //Base case
        if(postOrderIndex <0 || inOrderStart > inOrderEnd)
        {
            return NULL;
        }
        
        int ele = post[postOrderIndex--];
        Node* root = new Node(ele);
        
        int pos = position(in, ele , n);
        
        
        //Recursive Call for root_right
        root->right = solve(in, post, postOrderIndex, pos+1, inOrderEnd, n);

        //Recursive Call for root _left
        root->left = solve(in, post, postOrderIndex, inOrderStart, pos-1, n);
        
        return root;
    }
    
Node *buildTree(int in[], int post[], int n) {
    int postOrderIndex = n-1;
    Node * ans = solve(in, post, postOrderIndex,0,n-1,n);
    return ans;
}
