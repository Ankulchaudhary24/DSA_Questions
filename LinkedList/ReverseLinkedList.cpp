/***
Given a linked list of N nodes. The task is to reverse this list.

Input:
LinkedList: 1->2->3->4->5->6
Output: 6 5 4 3 2 1
Explanation: After reversing the list, 
elements are 6->5->4->3->2->1.

*///

//Iterative Approach
struct Node* reverseList(struct Node *head)
    {
        Node* nxt, *prev=NULL, *curr=head;
        while(curr!=NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            
        }
        return prev;
    }

//Recursive Approach
 struct Node* reverseList(struct Node *head)
    {
        if(head ==NULL || head->next == NULL) //checking if the head is NUll or head contains only one node
        return head;
        
        Node* chotaHead = reverseList(head->next);  //Chota head means the head of the reverse linkedList except the current node
        head->next->next = head;  
        head->next =NULL;
        
        return chotaHead;
    }
