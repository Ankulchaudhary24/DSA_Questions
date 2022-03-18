/*

Given an array of size N. The task is to sort the array elements by
completing functions heapify() and buildHeap() which are used to implement Heap Sort.

Example 1:

Input:
N = 5
arr[] = {4,1,3,9,7}
Output:
1 3 4 7 9
Explanation:
After sorting elements
using heap sort, elements will be
in order as 1,3,4,7,9.

*/
//Heapify function to maintain heap property.

    void heapify(int arr[], int n, int i)  
    {
        
        int largest = i;
        int leftCh = 2*i + 1;
        int rightCh = 2*i + 2;
        
        if(leftCh < n && arr[largest] < arr[leftCh])
        {
            largest = leftCh;
        }
        
        if(rightCh < n && arr[largest] < arr[rightCh])
        {
            largest = rightCh;
        }
        
        if(largest != i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    
         for(int i = n/2;i>=0;i--){
            heapify(arr,n,i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
       buildHeap(arr,n);
       for(int i =n-1;i>0;i--){
           swap(arr[0],arr[i]);
           heapify(arr,i,0);
       }
    }
