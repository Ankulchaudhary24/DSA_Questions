/*
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer.

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every 
node in a single level.
(Note: | represents the bottom pointer.)

*/
//Approach:
Node* merge(Node* left, Node* right) {
    
    if(left == NULL)
        return right;
    
    if(right == NULL)
        return left;
    
    Node* ans = new Node(-1);
    Node* temp = ans;
    
    //merge 2 sorted Linked List
    while(left != NULL && right != NULL) {
        if(left -> data < right -> data ) {
            temp -> bottom = left;
            temp = left;
            left = left -> bottom;
        }
        else
        {
            temp -> bottom = right;
            temp = right;
            right = right -> bottom;
        }
    }
    
    while(left != NULL) {
        temp -> bottom = left;
        temp = left;
        left = left -> bottom;
    }
    
    while(right != NULL) {
        temp -> bottom = right;
        temp = right;
        right = right -> bottom;
    }
    
    ans = ans -> bottom;
    return ans;
    
}
/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   if(root==NULL)
    return NULL;
   Node* down = root;
   Node* right = flatten(root->next);
   Node* ans = merge(down,right);
   return ans;
}
