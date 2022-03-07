/*

Given a number and its reverse. Find that number raised to the power of its own reverse.
Note: As answers can be very large, print the result modulo 109 + 7.

Example 1:

Input:
N = 2
Output: 4
Explanation: The reverse of 2 is 2
and after raising power of 2 by 2 
we get 4 which gives remainder as 
4 by dividing 1000000007.

*/

long long power(int N,int R)
    {
        if(R == 0)
        return 1;
        long long ans = power(N,R/2);
        ans =  (ans*ans)%1000000007;
        if(R&1 ==1)
        return ans*N%1000000007;
        else
        return ans;
    }
