/***
Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.
***/

long long maxSubarraySum(int arr[], int n){
        
        int sum = 0;  //storing the maximum sum till the current postion 
        int maxtillnow = arr[0];  // Used to store the maximum sum till the position the sum is traversing
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
            if(sum>maxtillnow) maxtillnow = sum;
            if(sum<0) sum = 0;
        }
        
        
        return maxtillnow;
        
    }
