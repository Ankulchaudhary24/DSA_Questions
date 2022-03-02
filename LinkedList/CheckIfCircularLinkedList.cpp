/*
Given head, the head of a singly linked list, find if the linked list is circular or not. 
A linked list is called circular if it not NULL terminated and all nodes are connected in the form of a cycle.
An empty linked list is considered as circular.

Note: The linked list does not contains any inner loop.

Input:
LinkedList: 1->2->3->4->5
(the first and last node is connected,
i.e. 5 --> 1)
Output: 1

*/


//Same Approach as to print the Nodes data in cicular Linked List
bool isCircular(Node *head)
{
   if(head == NULL)
   return true;
   
   Node *temp = head;
   while(temp!=NULL){
      temp = temp->next;
       if(head == temp){
           return true;
       }
   }
   return false;
}


//Same approach as to find the loop in the linkedList
bool isCircular(Node *head)
{
   if(head == NULL)
   return true;
   Node *slow =head, *fast = head;
   while(fast!=NULL && fast->next!=NULL){
       fast = fast->next->next;
       slow = slow->next;
       if(slow ==fast){
           return true;
       }
   }
   return false;
}
