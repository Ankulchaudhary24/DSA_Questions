/*

The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes.
The diagram below shows two trees each with diameter nine,
the leaves that form the ends of the longest path are shaded 
(note that there is more than one path in each tree of length nine, but no path longer than nine nodes). 

Example 1:

Input:
       1
     /  \
    2    3
Output: 3
Example 2:

Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4

*/

int height(struct Node* node){
        if(node ==NULL)
        return 0;
        
        int left = height(node->left);
        int right= height(node->right);
        
        int ans = max(left,right)+1;
        return ans;
        
    }
    
    int diameter(Node* root) {
        if(root ==NULL)
        return 0;
        
        int left = diameter(root->left);
        int right = diameter(root->right);
        int  h = height(root->left)+height(root->right);
        int dia = max(h+1,max(left,right));
        return dia;
        
    }
