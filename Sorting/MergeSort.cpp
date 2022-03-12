/*
Given an array arr[], its starting position l and its ending position r. Sort the array using merge sort algorithm.
Example 1:

Input:
N = 5
arr[] = {4 1 3 9 7}
Output:
1 3 4 7 9
Example 2:

Input:
N = 10
arr[] = {10 9 8 7 6 5 4 3 2 1}
Output:
1 2 3 4 5 6 7 8 9 10
*/

void merge(int arr[], int s, int m, int e)
    {
         int len1 = m-s+1;
         int len2 = e-m;
         
         int *first = new int[len1];
         int *second = new int[len2];
         
         int mainArrayIndex = s;
            for(int i=0; i<len1; i++) {
                first[i] = arr[mainArrayIndex++];
            }

            // mainArrayIndex = m+1;
            for(int i=0; i<len2; i++) {
                second[i] = arr[mainArrayIndex++];
            }

            //merge 2 sorted arrays     
            int index1 = 0;
            int index2 = 0;
            mainArrayIndex = s;
        
            while(index1 < len1 && index2 < len2) {
                if(first[index1] < second[index2]) {
                    arr[mainArrayIndex++] = first[index1++];
                }
                else{
                    arr[mainArrayIndex++] = second[index2++];
                }
            }   
            
                while(index1 < len1) {
                    arr[mainArrayIndex++] = first[index1++];
                }
            
                while(index2 < len2 ) {
                    arr[mainArrayIndex++] = second[index2++];
                }
            
                delete []first;
                delete []second;
                     
       }
       
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r)
        return;
        
        int mid = l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
