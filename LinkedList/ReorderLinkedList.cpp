/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

*/

 ListNode* reverse(ListNode * head){
         
        ListNode* nxt, *prev=NULL, *curr=head;
        while(curr!=NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            
        }
        return prev;
     }
    
    void reorderList(ListNode* head) {
        //step1 finding the mid element
        ListNode*slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
      
        //Step2 Reversing the List after mid element onward
        ListNode* mid = reverse(slow->next);
        
        //Step3 traversing the list till the second list becomes empty
        // ex: 1,2,3,4,5,6,7,8 becomes 1 2 3 4 and 8 7 6 5
        // Now joining them by traversing 
        slow->next = NULL;
        slow = head;
        ListNode * nxt1 ,*nxt2; 
        while(mid != NULL)
        {
            nxt1 = slow->next;
            nxt2 = mid->next;
            
            slow->next = mid;
            mid->next = nxt1;
            slow =nxt1;
            mid = nxt2;
        }
    }
