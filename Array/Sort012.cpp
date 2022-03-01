/***
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
***/

void sort012(int arr[], int n)
    {
  
   // Make the three pointers, "s" is to point to the position of 0 , "e" pointing to the 2 and "i" is used for the traversal
    int s = 0, e = n-1,i=0;
  
    while(i<=e){
        if(arr[i]==0){
            swap(arr[s],arr[i]);
            s++;  
            i++;
        }
        else if(arr[i]==2){
         swap(arr[e],arr[i]);
         e--;
    }
        else
         i++;
        
    } 
    }
    
