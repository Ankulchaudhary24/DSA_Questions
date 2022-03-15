/*

Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal. 

Example 1:

Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1
Example 2:

Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5

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
    
    Node* solve(int in[], int pre[], int &preOrderIndex, int inOrderStart, int inOrderEnd, int n)
    {
        //Base case
        if(preOrderIndex >=n || inOrderStart > inOrderEnd)
        {
            return NULL;
        }
        
        int ele = pre[preOrderIndex++];
        Node* root = new Node(ele);
        
        int pos = position(in, ele , n);
        
        //Recursive Call for root _left
        root->left = solve(in, pre, preOrderIndex, inOrderStart, pos-1, n);
        
        //Recursive Call for root_right
        root->right = solve(in, pre, preOrderIndex, pos+1, inOrderEnd, n);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex =0;
        Node * ans = solve(in, pre, preOrderIndex,0,n-1,n);
        return ans;
    }
