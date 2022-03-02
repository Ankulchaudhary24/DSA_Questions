/*
Given a singly linked list of N nodes.
The task is to find the middle of the linked list. For example, if the linked list is
1-> 2->3->4->5, then the middle node of the list is 3.
If there are two middle nodes(in case, when N is even), print the second middle element.
For example, if the linked list given is 1->2->3->4->5->6, then the middle node of the list is 4.

Input:
LinkedList: 1->2->3->4->5
Output: 3 
Explanation: 
Middle of linked list is 3.

*/

//First Approach is to Count the number of the nodes in the linked list than again traversing the linked list till the middle element.
int getMiddle(Node *head)
    {
        int n =0;
        Node * temp = head;
        while(temp!=NULL){
            temp = temp->next;
            n++;
        }
        n = n/2;
        temp = head;
        while(n != 0){
            temp = temp->next;
            n--;
        }
        return temp->data;
    }

//Second approach is to use the two pointer named fast and slow
int getMiddle(Node *head)
    {
        Node* slow =head, *fast = head;
        while(fast != NULL && fast->next !=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow->data;
    }
