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

//Recursive Solution taking the O(n2) time

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

//Recursive Solution taking the O(n) time

//In the pair the first int is for the diameter and second int is for the height

pair<int,int> diaHeightTogether(struct Node* node){
        if(node ==NULL)
        {
            pair<int,int> p = make_pair(0,0); // if the node is null both height and diameter will be 0
            return p;
        }
        
        pair<int,int> left = diaHeightTogether(node->left); //calling for the diameter of left part
        pair<int,int> right= diaHeightTogether(node->right); //calling for the diameter of the right part
        
        int opt1 = left.first;  // for the diameter of the left part
        int opt2 = right.first; // for the diameter of the right part
        int opt3 = left.second + right.second + 1; //for the diameter of the tree cosisting if the root node
       
        pair<int,int> ans;
        ans.first = max(opt3,max(opt1,opt2));  // ans.first is for the diameter of the tree
        ans.second = max(left.second,right.second)+1; //ans.second is for the height of the tree
        return ans;
        
    }
    
    int diameter(Node* root) {
        return diaHeightTogether(root).first;
    }
