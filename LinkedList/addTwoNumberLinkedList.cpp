/*

Given two numbers represented by two linked lists of size N and M. The task is to return a sum list.

The sum list is a linked list representation of the addition of two input numbers from the last.

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).

*/

//Approach: 
//step1 Reverse both the linkedList as we sum the numbers from backwards
//Step2 Add the elements and create the new linkedList from them
//step3 Check if first linked list has some elements to insert
//Step4 Check if second linked list has some elements to insert
//step5 check if carry is zero or not
//Step6 Reverse the LinkedList

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
    
    void insertAtTail(Node* &curr, int value){
        Node* n = new Node(value);
        curr->next = n;
        curr = n;
    }

    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
      
       //step1 Reverse both the linkedList as we sum the numbers from backwards
        first = reverseList(first);
        second = reverseList(second);
        int sum = 0;
        int carry = 0;
        Node* head = new Node(-1);
        Node* tail= head;
      
      //Step2 Add the elements and create the new linkedList from them
        while(first!=NULL && second!=NULL){
            sum = first->data+second->data+carry;
            carry = sum/10;
            sum = sum%10;
            insertAtTail(tail,sum);
            first = first->next;
            second = second->next;
        }
      
      //step3 Check if first linked list has some elements to insert
        while(first!=NULL){
            sum = first->data+carry;
            carry = sum/10;
            sum = sum%10;
            insertAtTail(tail,sum);
            first = first->next;
        }
      
      //Step4 Check if second linked list has some elements to insert
        while(second!=NULL){
            sum = second->data+carry;
            carry = sum/10;
            sum = sum%10;
            insertAtTail(tail,sum);
            second = second->next;
        }
      
      //step5 check if carry is zero or not
        if(carry!=0){
            insertAtTail(tail,carry);
        }
      
      //Step6 Reverse the LinkedList
        head = reverseList(head->next);
        return head;
    }
