/*
You are given an array (0-based indexing) of positive integers 
and you have to tell how many different ways of selecting the elements from the array 
are there such that the sum of chosen elements is equal to the target number “tar”.

*/

//Similar to the approach of the subset sum
//Here only the space optmized approach is given

int findWays(vector<int> &num, int k)
{
    int n = num.size();

    vector<int> prev(k+1,0);
    
    prev[0] =1;
    
    if(num[0]<=k)
        prev[num[0]] = 1;
    
    for(int ind = 1; ind<n; ind++){
        vector<int> cur(k+1,0);
        cur[0]=1;
        for(int target= 1; target<=k; target++){
            
            int notTaken = prev[target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = prev[target-num[ind]];
        
            cur[target]= notTaken + taken;
        }
        
        prev = cur;
    }
    
    return prev[k];

}
