/*
Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.
If the number of nodes is not a multiple of k then left-out nodes, in the end, should be considered as a group and must be reversed.

LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5 
Explanation: 
The first 4 elements 1,2,2,4 are reversed first 
and then the next 4 elements 5,6,7,8. Hence, the 
resultant linked list is 4->2->2->1->8->7->6->5.

Input:
LinkedList: 1->2->3->4->5
K = 3
Output: 3 2 1 5 4 
Explanation: 
The first 3 elements are 1,2,3 are reversed 
first and then elements 4,5 are reversed.Hence, 
the resultant linked list is 3->2->1->5->4.
*/


//Recursive Approach in which we first iteratively reversing the first k nodes and then calling function for the rest of the nodes
struct node *reverse (struct node *head, int k)
    { 
        //base case
        if(head ==NULL)
        return NULL;
        
        //Reverse the First K nodes
        node *nxt =NULL, *curr = head, *prev = NULL;
        int count =0;
        while(curr!=NULL && count<k){
            nxt = curr->next;
            curr->next= prev;
            prev = curr;
            curr = nxt;
            count++;
        }
        
        //Recursion will take care of the next part
        if(nxt != NULL){
            head->next = reverse(nxt,k);
        }
        
        //Return the output which is prev as the head of the reversed linked list
        return prev;
    }
