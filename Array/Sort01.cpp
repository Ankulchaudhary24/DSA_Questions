/*** INTRODUCTION:
Given an array of length N consisting of only 0s and 1s in random order. Modify the array to segregate 0s on left side and 1s on the right side of the array.
***/


void segregate0and1(int v[], int n) {
    
    //creating the pointers "l" and "r" for tracking the left and right position of the array
    int l=0,r=n-1;
    
    //Traverse the array till both the pointers crossed each other
    while(l<=r)
    {
        //if the value at the place at l is 0 then simply move to the right direction
        if(v[l]==0)
        {
        
            //if the value at r is 1 then simply update the both pointers
            if(v[r]==1)
            {
                l++;
                r--;
            }
            
            //if the value at pointer r is also 0 then move only the l pointer
            else
            l++;
        }
        
        //Also check same for the 1, and if the value at r is 0 and l is 1 then swap 
        else{
            if(v[r]==0)
            {
                swap(v[l],v[r]);
                l++;
                r--;
            }
            else
            r--;
        }
    }
    }
