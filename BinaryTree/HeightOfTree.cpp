/*

Given a binary tree, find its height.


Example 1:

Input:
     1
    /  \
   2    3
Output: 2
Example 2:

Input:
  2
   \
    1
   /
 3
Output: 3   

*/

//Recursive Solution
int height(struct Node* node)
{
        if(node ==NULL)
        return 0;
        
        int left = height(node->left);
        int right= height(node->right);
        
        int ans = max(left,right)+1;
        return ans;
        
}
