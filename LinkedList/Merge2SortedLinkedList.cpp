/*
Given two sorted linked lists consisting of N and M nodes respectively. 
The task is to merge both of the list (in-place) and return head of the merged list.

Input:
N = 4, M = 3 
valueN[] = {5,10,15,40}
valueM[] = {2,3,20}
Output: 2 3 5 10 15 20 40
Explanation: After merging the two linked
lists, we have merged list as 2, 3, 5,
10, 15, 20, 40.

*/

//We will be checking if the element of the second list can be inserted in between the first list element or not
Node* solve(Node * first, Node* second){
    //if only one element is present in first list
    if(first->next == NULL){
        first->next = second;
        return first;
    }
    Node* curr1 = first;
    Node *next1 = curr1->next;
    Node *curr2 = second;
    Node* next2 = curr2->next;
    
    while(next1 !=NULL && curr2 !=NULL){
        
        if( (curr2 -> data >= curr1 -> data ) && ( curr2 -> data <= next1 -> data)) {
            
            curr1 -> next = curr2;
            next2 = curr2->next;
            curr2 -> next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            curr1 = curr1->next;
            next1 = next1->next;
            if(next1 ==NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }
     return first;
}

Node* sortedMerge(Node* head1, Node* head2)  
{  
    if(head1 == NULL)
    return head2;
    
    if(head2 == NULL)
    return head1;
    
    if(head1->data <= head2->data){
        return solve(head1,head2);
    }
    
    else{
       return solve(head2,head1);
    }
}  
