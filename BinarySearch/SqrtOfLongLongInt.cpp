/*
You are given a positive integer ‘N’. Your task is to find and return its square root. If ‘N’ is not a perfect square, then return the floor value of sqrt(N).
For example:
For ‘N’  = 25, return 5 , for ‘N’ = 20 return 4, for ‘N’ = 2 return 1.
Input Format:
The first line of input contains an integer ‘T’, denoting the number of test cases. Then each test case follows.

The first and the only line of each test case contains the Integer ‘N’.
Output Format:
For each test case, print a single line containing an integer denoting the square root of ‘N’.

The output of each test case will be printed on a separate line.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 5
0 <= N <= 10 ^ 16

Time Limit: 1 sec.

*/

int sqrtN(long long int N)
{
    if(N==0 || N==1)  //check base cases if number is 0 or 1
        return N;
  
    long long s =0;
    long long e =N/2+1;
    long long m = s+(e-s)/2;
    long long ans =-1;
  
    while(s<=e){
        if(m >N/m)  //INSTEAD OF USING M*M >N USE M>N/M to avoid overflow
            e = m-1;
        else{
            ans =m;
            s = m+1;
        }
         m = s+(e-s)/2;
    }
    return ans;
}
