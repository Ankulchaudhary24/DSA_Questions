/*
Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.

*/

//Approach 1::
//step1 Finding the middle element of the linked list
//Step2 Reverse the LinkedList form middle element to the end
//Step3 Compare the element from head to the mid and from mid to the end

 Node* reverse(Node * head){
         
        Node* nxt, *prev=NULL, *curr=head;
        while(curr!=NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            
        }
        return prev;
     }

    //Function to check whether the list is palindrome.

    bool isPalindrome(Node *head)
    {
      //step1 finding the mid element
        Node*slow = head;
        Node* fast = head;
        while(fast!=NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
      
      //Step2 Reversing the List from mid element onward
        Node* mid = reverse(slow);
      
      //Step3 Checking for Palindrome
        Node* start = head;
        while(mid != NULL){
            if(start->data != mid->data)
            return false;
            mid = mid->next;
            start = start->next;
        }
        return true;
    }
