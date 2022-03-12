    long long int inversionCount(long long arr[], long long N)
    {
        return count(arr,0,N-1);
    }
    
    
     long long merge(long long arr[] ,long long s ,long long e){
        long long ans = 0;

        long long mid = s+(e - s)/2;

        long long l1 = mid - s + 1;
        long long l2 = e - mid;

        long long *a1 = new long long int[l1];
        long long *a2 = new long long int[l2];

        long long idx = s;

        //copy elements
        for(long long  i = 0; i < l1; i++){
            a1[i] = arr[idx++];
        }

        for(long long i = 0; i < l2; i++){
            a2[i] = arr[idx++];
        }

        long long  idx1 = 0;
        long long idx2 = 0;
        idx =  s;
        while(idx1 < l1 && idx2 < l2){
            //check for inversions

            if(a1[idx1] > a2[idx2]){
                ans += (l1 - idx1);

                arr[idx++] = a2[idx2++];
            }
            else {
                arr[idx++] = a1[idx1++];
            }
        }

        while(idx1 < l1){
            arr[idx++] = a1[idx1++];
        }
        while(idx2 < l2){
            arr[idx++] = a2[idx2++];
        }

        return ans;
    }
    
     long long count(long long arr[] ,long long s ,long long e){
        //base case
        if(s >= e)
            return 0;

        long long mid = s+(e - s) / 2;

        //left Part inversion
        long long inv = count(arr , s , mid);
        inv += count(arr , mid + 1 , e);
        inv += merge(arr , s , e);
        return inv;
    }
    
