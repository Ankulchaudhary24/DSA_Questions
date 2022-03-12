/*

You are given N elements and your task is to Implement a Stack in which you can get minimum element in O(1) time.

Example 1:

Input:
push(2)
push(3)
pop()
getMin()
push(1)
getMin()
Output: 3 2 1
Explanation: In the first test case for
query 
push(2)  the stack will be {2}
push(3)  the stack will be {2 3}
pop()    poped element will be 3 the
         stack will be {2}
getMin() min element will be 2 
push(1)  the stack will be {2 1}
getMin() min element will be 1

*/
class Solution{
    int minEle;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           if(s.empty())
             return -1;
           return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
           if(s.empty())
           return -1;
            int curr = s.top();
            s.pop();
           if(curr>minEle)
           {
               return curr;
               
           }
           else
           {
               int prevMin = minEle;
               int val = 2*minEle -curr;
               minEle = val;
               return prevMin;
           }
           
       }
       
       /*push element x into the stack*/
       void push(int x){
           //for first element
           if(s.empty())
           {
               s.push(x);
               minEle = x;
           }
           else
           {
               if(x<minEle)
               {
                   int curr = 2*x -minEle;
                   s.push(curr);
                   minEle = x;
               }
               else
               s.push(x);
           }
       }
};
