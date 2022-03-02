/*
Given a singly linked list consisting of N nodes. The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).
Note: Try not to use extra space. Expected time complexity is O(N). The nodes are arranged in a sorted way.

Input:
LinkedList: 2->2->4->5
Output: 2 4 5
Explanation: In the given linked list 
2 ->2 -> 4-> 5, only 2 occurs more 
than 1 time.

*/

Node *removeDuplicates(Node *head)
{
   if(head == NULL)
   return head;
  
   Node*temp = head; //pointer for traversing the list
  
   while(temp!=NULL&& temp->next!=NULL){
     
       if(temp->data==temp->next->data){
           Node* t = temp->next;
           temp->next = temp->next->next;
           delete(t); //Handling the freed pointers
       }
       else{
           temp = temp->next;
       }
   }
   return head;
}
