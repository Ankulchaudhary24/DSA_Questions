/*
Given a stack with push(), pop(), empty() operations, delete the middle of the stack without using any additional data structure.
Middle: ceil(size_of_stack/2.0)
 

Example 1:

Input: 
Stack = {1, 2, 3, 4, 5}
Output:
ModifiedStack = {1, 2, 4, 5}
Explanation:
As the number of elements is 5 , 
hence the middle element will be the 3rd
element which is deleted

*/

void solve(stack<int>&s,int count, int size){
        if(count == size/2)
         {
             s.pop();
             return;
         }
         int ele = s.top();
         s.pop();
         solve(s,count+1,size);
         s.push(ele);
         
    }

//Function to delete middle element of a stack.
void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int count=0;
        solve(s,count,sizeOfStack);
    }
