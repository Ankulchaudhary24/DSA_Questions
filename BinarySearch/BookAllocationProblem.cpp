/*

You are given N number of books. Every ith book has Ai number of pages.

You have to allocate contagious books to M number of students. There can be many ways or permutations to do so.
In each permutation, one of the M students will be allocated the maximum number of pages.
Out of all these permutations, the task is to find that particular permutation in which
the maximum number of pages allocated to a student is the minimum of those in all the other permutations and print this minimum value.

Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

 

Example 1:

Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:113
Explanation:Allocation can be done in 
following ways:{12} and {34, 67, 90} 
Maximum Pages = 191{12, 34} and {67, 90} 
Maximum Pages = 157{12, 34, 67} and {90} 
Maximum Pages =113. Therefore, the minimum 
of these cases is 113, which is selected 
as the output.

Example 2:

Input:
N = 3
A[] = {15,17,20}
M = 2
Output:32
Explanation: Allocation is done as
{15,17} and {20}

*/

bool isPossible(int arr[], int n , int M, int mid){
        int studentCount =1;
        int pageSum =0;
        
        for(int i =0;i<n;i++){
            if(pageSum + arr[i] <= mid)
            pageSum =pageSum + arr[i];
            
            else{
                studentCount++;
                if(studentCount >M || arr[i]>mid){
                    return false;
                }
                pageSum =0;
                pageSum =arr[i];
            }
        }
        return true;
    }

    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int M) 
    {
        int s =0;
        int sum =0;
        for(int i=0;i<n;i++)
           sum+=arr[i];
        int e = sum;
        int mid = s+(e-s)/2;
        int ans =-1;
        while(s<=e){
            if(isPossible(arr,n,M,mid)){
                ans = mid;
                e = mid-1;
            }
            else
                s = mid+1;
            mid = s+(e-s)/2;
        }
        return ans;
    }
