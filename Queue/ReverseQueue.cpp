/*

Given a Queue Q containing N elements. The task is to reverse the Queue.
Your task is to complete the function rev(), that reverses the N elements of the queue.

Example 1:

Input:
6
4 3 1 10 2 6

Output: 
6 2 10 1 3 4

Explanation: 
After reversing the given
elements of the queue , the resultant
queue will be 6 2 10 1 3 4.

*/

//Using the Stack
queue<int> rev(queue<int> q)
{
    stack<int> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    return q;
}

//Using recursion
void reverse(queue<int> &q){
   if(q.size() > 1){
       int x = q.front();
       q.pop();
       reverse(q);
       q.push(x);
   }
}

queue<int> rev(queue<int> q)
{
   reverse(q);
   return (q);
}
