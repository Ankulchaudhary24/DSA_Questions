/*
Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List.
When a value appears in multiple nodes, the node which appeared first should be kept, all others duplicates are to be removed.

N = 4
value[] = {5,2,2,4}
Output: 5 2 4
Explanation:Given linked list elements are
5->2->2->4, in which 2 is repeated only.
So, we will delete the extra repeated
elements 2 from the linked list and the
resultant linked list will contain 5->2->4

*/

//Appraoch 1:: Traversing the Linked List with the two loops and deleting the duplicates if found O(n2) solution
Node * removeDuplicates( Node *head) 
    {
     Node*curr = head;
     while(curr!=NULL){
         Node*temp = curr->next,*prev = curr;
         while(temp != NULL){
             if(temp->data == curr->data){
                 Node* t = temp;
                 prev->next = temp->next;
                 temp = temp->next;
                 delete(t);
             }
             else{
                 temp=temp->next;
                 prev = prev->next;
             }
         }
         curr= curr->next;
     }
     return head;
    }

//Appraoch 2 :: Use the set(hasing) to store the data about the nodes that have been traversed till now and if duplicated found then remove them
Node * removeDuplicates( Node *head) 
    {
        if(head==NULL || head->next ==NULL)
        return head;
  
        Node*curr = head->next,*prev=head;
  
        unordered_set<int> isPresent;
  
        isPresent.insert(prev->data);
        while(curr!=NULL){
         if(isPresent.find(curr->data)!=isPresent.end()){
                 Node* t = curr;
                 prev->next = curr->next;
                 curr = curr->next;
                 delete(t);
         }
         else{
                 isPresent.insert(curr->data);
                 curr=curr->next;
                 prev = prev->next;
             }
     }
     return head;
    }
