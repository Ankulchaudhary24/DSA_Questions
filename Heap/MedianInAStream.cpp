/*

Given that integers are read from a data stream.
Your task is to find the median of the elements read so far.

Median is the middle value in an ordered integer list. 
If the size of the list is even there is no middle value.
So the median is the floor of the average of the two middle values.
For Example :
[2,3,4] - median is 3.
[2,3] - median is floor((2+3)/2) = 2.

*/

#include<queue>    
    
//Function to balance heaps.
void balanceHeaps(priority_queue<int> &maxHeap, priority_queue<int,vector<int>,greater<int>>&minHeap)
    {
        if(maxHeap.size()>minHeap.size() and (maxHeap.size()-minHeap.size())>1)
        {
            int t=maxHeap.top();
            maxHeap.pop();
            minHeap.push(t);
        }
        
        else if(minHeap.size()>maxHeap.size() and (minHeap.size()-maxHeap.size())>1)
        {
            int t=minHeap.top();
            minHeap.pop();
            maxHeap.push(t);
        }
}
  

//Function to insert heap.
void insertHeap(int &x,priority_queue<int> &maxHeap, priority_queue<int,vector<int>,greater<int>>&minHeap)
    {
        if(maxHeap.size() == 0)
       {
           maxHeap.push(x);
       }
       
       else if(x < maxHeap.top())
       {
           maxHeap.push(x);
       }
       
       else
       {
           minHeap.push(x);
       }
       balanceHeaps(maxHeap, minHeap);
}
  
//Function to return Median.
int getMedian(priority_queue<int> &maxHeap, priority_queue<int,vector<int>,greater<int>>&minHeap)
    {
        if(maxHeap.size()==minHeap.size())
       {
           return ((maxHeap.top()+minHeap.top())/2);
       }
       
       else 
       {
           if(maxHeap.size()>minHeap.size())   return maxHeap.top();
           else    return minHeap.top();
       }
}

vector<int> findMedian(vector<int> &arr, int n){
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
	vector<int> ans;
    for(int i=0; i<n;i++)
    {
        insertHeap(arr[i], maxHeap, minHeap);
        ans.push_back(getMedian(maxHeap, minHeap));
    }
    return ans;
}
