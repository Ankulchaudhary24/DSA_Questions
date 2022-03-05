/*

Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:

Input:
Stack: 3 2 1
Output: 3 2 1
Example 2:

Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2

*/

void insertInSortedOrder(stack<int>&s, int ele){
    if(s.empty() || s.top()<ele){
        s.push(ele);
        return;
    }
    int num = s.top();
    s.pop();
    insertInSortedOrder(s,ele);
    s.push(num);
}

void SortedStack :: sort()
{
   if(s.empty())
   return;
   
   int ele = s.top();
   s.pop();
   sort();
   insertInSortedOrder(s,ele);
}
