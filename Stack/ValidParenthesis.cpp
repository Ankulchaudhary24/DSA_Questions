/*

Given a string S, composed of different combinations of '(' , ')', '{', '}', '[', ']'. The task is to verify the validity of the arrangement.
Note: Ignore the precedence of brackets.

Example 1:

Input:
S = ()[]{}
Output: 1
Explanation: The arrangement is valid.
 

Example 2:

Input:
S = ())({}
Output: 0
Explanation: Arrangement is not valid.
*/

bool valid(string s)
{
    stack<char> st;
    for(char ch : s){
        
        if(ch =='{' || ch =='(' || ch =='[')
        st.push(ch);
        
        else{
            if(!st.empty()){
                char top = st.top();
                if((ch ==']'&& top =='[')||
                   (ch =='}'&& top =='{')||
                   (ch ==')'&& top =='('))
                   {
                       st.pop();
                   }
                   else{
                       return false;
                   }
            }
            else{
                return false;
            }
        }
    }
    if(!st.empty())
    return false;
    else
    return true;
}
