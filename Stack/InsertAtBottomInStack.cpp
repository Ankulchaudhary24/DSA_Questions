/*
You are given a stack/deque of integers 'MY-STACK' and an integer ‘X’.
Your task is to insert ‘X’ to the bottom of ‘MY-STACK’ and return the updated stack/deque.

For Example :
Let ‘MY_STACK’ = [7, 1, 4, 5] and ‘X’ = 9. So, ‘MY_STACK’ after insertion becomes [9, 7, 1, 4, 5].

*/

void pb(stack<int>& myStack, int x){
    if(myStack.empty()){
        myStack.push(x);
        return ;
    }
    int ele = myStack.top();
    myStack.pop();
    pb(myStack,x);
    myStack.push(ele);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    pb(myStack,x);
    return myStack;
}
