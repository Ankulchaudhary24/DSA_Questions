/*
Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. 
The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side,
2s at the end of the linked list, and 1s in the mid of 0s and 2s.

Input:
N = 8
value[] = {1,2,2,1,2,0,2,2}
Output: 0 1 1 2 2 2 2 2
Explanation: All the 0s are segregated
to the left end of the linked list,
2s to the right end of the list, and
1s in between.

*/

//Approach 1:: Counting the numbers of 0,1 and 2's in the linked list and then assigning them to the linked list
// Use this if the data replacement is Allowed
Node* segregate(Node *head) {
       int z =0, o = 0, t =0;
       Node *temp = head;
       while(temp!=NULL){
           if(temp->data ==0)
           z++;
           else if(temp->data == 1)
           o++;
           else
           t++;
           temp = temp->next;
       }
       temp = head;
       while(temp != NULL){
           if(z){
               while(z !=0){
                   temp->data = 0;
                   temp = temp->next;
                   z--;
               }
           }
           else if(o){
                while(o !=0){
                   temp->data = 1;
                   temp = temp->next;
                   o--;
               }
           }
           else{
                while(t !=0){
                   temp->data = 2;
                   temp = temp->next;
                   t--;
               }
           }
           }
           return head;
       }

//Apprach 2:: Changing the links and making the linked list sorted
// Use this if the data replacement is not allowed

    void insertAtTail(Node* &tail, Node* curr){
        tail->next = curr;
        tail = curr;
    }
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;
        Node* oneHead = new Node(-1);
        Node* oneTail = oneHead;
        Node* twoHead = new Node(-1);
        Node* twoTail = twoHead;
        
        Node* curr = head;
    
        // create separate list 0s, 1s and 2s
        while(curr != NULL) {
        
        int value = curr -> data;
        
        if(value == 0) {
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1) {
            insertAtTail(oneTail, curr);
        }
        else if(value == 2) {
            insertAtTail(twoTail, curr);
        }       
        curr = curr -> next;
        }
        
    //merge 3 sublist
    
    // 1s list not empty
    if(oneHead -> next != NULL) {
        zeroTail -> next = oneHead -> next;
    }
    else {
        //1s list -> empty
        zeroTail -> next = twoHead -> next;
    }
    
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;
    
	  //setup head 
    head = zeroHead -> next;
    
    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
    }
