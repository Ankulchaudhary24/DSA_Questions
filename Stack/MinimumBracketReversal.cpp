/*

Ninja has been given a string ‘STR’ containing either ‘{’ or ‘}’.
'STR’ is called valid if all the brackets are balanced.
Formally for each opening bracket, there must be a closing bracket right to it.

For Example:
“{}{}”, “{{}}”, “{{}{}}” are valid strings while “}{}”, “{}}{{}”, “{{}}}{“ are not valid strings.

Sample Input 1:
2
{{{}
{{}{}}
Sample Output 1:
1
0

*/

//Approach:
//Step 1: if the length of the string is odd then simply return -1 as odd number of brackets cannot be make balanced
//step 2: Make a stack and traverse the whole string the if the closed bracket is found check if stack.top() is open bracket if yes then pop
// else push the bracket onto the stack and push the open bracket onto the stack;
//step 3: count the number of open and closed brackets
//Step 4: answer will be openBracketCount+1/2 +closedBracketCount+1/2

int findMinimumCost(string str) {
    if(str.length()%2!=0)
        return -1;
    stack<char> st;
  for(char ch : str){
      if(ch =='}'){
          if(!st.empty()&&st.top()=='{')
              st.pop();
          else
              st.push(ch);
      }
      else
         st.push(ch);
  }
    int a =0, b=0;
    while(!st.empty()){
        if(st.top()=='{')
            a++;
        else
            b++;
        st.pop();
    }
    return (a+1)/2+(b+1)/2;
}
