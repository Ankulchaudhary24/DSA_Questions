/*

You are given an array 'ARR' of integers having 'N' elements.
Your task is to convert the input array into a min-Binary Heap.
A min-Binary heap is a complete binary tree in which the value of each internal
node is smaller than or equal to the values of the children of that node.

*/

void heapify(vector<int> &arr, int i, int size)
{
    int smallest = i;
    int leftCh = 2*i + 1;
    int rightCh = 2*i + 2;
    
    if(leftCh < size && arr[smallest] > arr[leftCh])
    {
        smallest = leftCh;
    }
    
    if(rightCh < size && arr[smallest] > arr[rightCh])
    {
        smallest = rightCh;
    }
    
    if(smallest != i){
        swap(arr[smallest],arr[i]);
        heapify(arr,smallest,size);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
    for(int i = n/2 ; i>=0;i--)
    {
        heapify(arr,i,n);
    }
    return arr;
}
