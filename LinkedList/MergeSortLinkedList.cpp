/*
Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

Input:
N = 5
value[]  = {3,5,2,4,1}
Output: 1 2 3 4 5
Explanation: After sorting the given
linked list, the resultant matrix
will be 1->2->3->4->5.

*/

//Appraoch: 
//Step 1: find the mid of the linkedList
//Step 2: Call mergeSort for the left linkedList
//Step 3: Call mergeSort for the right linkedList
//Step 4: Merge the left and right linked list part ( same as doing the merging of the two sorted arrays)

 node* findMid(node* head) 
     {
        node* slow = head;
        node* fast = head -> next;
        
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next; 
        }
        return slow;
     }
    
    node* merge(node* left, node* right) {
        
        if(left == NULL)
            return right;
        
        if(right == NULL)
            return left;
        
        node* ans = new node(-1);
        node* temp = ans;
        
        //merge 2 sorted Linked List
        while(left != NULL && right != NULL) {
            if(left -> data < right -> data ) {
                temp -> next = left;
                temp = left;
                left = left -> next;
            }
            else
            {
                temp -> next = right;
                temp = right;
                right = right -> next;
            }
        }
        
        while(left != NULL) {
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        
        while(right != NULL) {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
        
        ans = ans -> next;
        return ans;
        
    }
    
    
    node* mergeSort(node *head) {
        //base case
        if( head == NULL || head -> next == NULL ) {
            return head;
        }
        
        // break linked list into 2 halvs, after finding mid
        node* mid = findMid(head);
        
        node* left = head;
        node* right = mid->next;
        mid -> next = NULL;
        
        //recursive calls to sort both halves
        left = mergeSort(left);
        right = mergeSort(right);
        
        //merge both left and right halves
        node* result = merge(left, right);
        
        return result;
    }
