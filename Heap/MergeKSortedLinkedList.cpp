/*
Given K sorted linked lists of different sizes.
The task is to merge them in such a way that after merging they will be a single sorted linked list.

Example 1:

Input:
K = 4
value = {{1,2,3},{4 5},{5 6},{7,8}}
Output: 1 2 3 4 5 5 6 7 8
Explanation:
The test case has 4 sorted linked 
list of size 3, 2, 2, 2
1st    list     1 -> 2-> 3
2nd   list      4->5
3rd    list      5->6
4th    list      7->8
The merged list will be
1->2->3->4->5->5->6->7->8.

*/

class compare{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int k)
    {
        priority_queue<Node*, vector<Node*> ,compare> pq;
        
        
        Node* head = NULL;
        Node* tail = NULL;
        
        if(k == 0)
            return head;
            
        //Step 1: insert first elements of all linked list
        for(int i=0; i<k;i++)
        {
            if(arr[i] != NULL)
            {
                pq.push(arr[i]);
            }
        }
        
        while(pq.size() > 0)
        {
            Node* topNode = pq.top();
            pq.pop();
            
            if(topNode ->next != NULL)
            {
                pq.push(topNode->next);
            }
            if(head == NULL)
            {
                head = topNode;
                tail = topNode;
            }
            
            else
            {
                tail ->next = topNode;
                tail = topNode;
            }
        }
        return head;
    }
};
