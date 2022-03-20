/*

Given K sorted lists of integers, KSortedArray[] of size N each.
The task is to find the smallest range that includes at least one
element from each of the K lists. If more than one such range's are found, return the first such range found.

Example 1:

Input:
N = 5, K = 3
KSortedArray[][] = {{1 3 5 7 9},
                    {0 2 4 6 8},
                    {2 3 5 7 11}}
Output: 1 2
Explanation: K = 3
A:[1 3 5 7 9]
B:[0 2 4 6 8]
C:[2 3 5 7 11]
Smallest range is formed by number 1
present in first list and 2 is present
in both 2nd and 3rd list.
*/

class node{
    public:
        int data;
        int row;
        int col;
        
        node(int data , int row, int col)
        {
            this->data = data;
            this->row = row;
            this->col = col;
        }
};

class compare
{
    public:
        bool operator()(node* a, node* b)
        {
            return a->data > b->data;
        }
};

class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        int mini = INT_MAX, maxi = INT_MIN;
        
        priority_queue<node*, vector<node*> , compare > minHeap;
       
        //Step 1: Inserting first element of all list in minHeap
        for(int i=0; i<k; i++)
        {
                int ele = KSortedArray[i][0];
                node* temp = new node(ele, i, 0);
                mini = min(mini, ele);
                maxi = max(maxi, ele);
                minHeap.push(temp);
        }
        
        int start = mini, end = maxi;
        
        while(minHeap.size() > 0)
        {
            node* topNode = minHeap.top();
            minHeap.pop();
            
            mini = topNode->data;
            
            if(maxi - mini < end - start)
            {
                end = maxi;
                start = mini;
            }
            
            if((topNode ->col)+1 < n)
            {
                maxi = max(maxi, KSortedArray[topNode->row][(topNode->col)+1]);
                node* temp = new node(KSortedArray[topNode->row][(topNode->col)+1], topNode->row,(topNode->col)+1);
                minHeap.push(temp);
            }
            else
            {
                break;
            }
        }
        
        return {start, end};
    }
};
