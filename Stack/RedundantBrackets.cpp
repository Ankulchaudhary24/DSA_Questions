/*

Given valid mathematical expressions in the form of a string.
You are supposed to return true if the given expression contains a pair of redundant brackets, else return false.
The given string only contains ‘(‘, ’)’, ‘+’, ‘-’, ‘*’, ‘/’ and lowercase English letters.

Note :
A pair of brackets is said to be redundant when a subexpression is surrounded by needless/ useless brackets.

Sample Input 1 :
2
(a+b)
(a+c*b)+(c))
Sample Output 1 :
No
Yes

*/

bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(char ch : s)
    {
        if(ch =='(' || ch =='+'||ch =='-'||ch =='/'||ch =='*')
            st.push(ch);
        else
        {
            //ch is a closing bracket or a lowerCase letter
            if(ch ==')'){
                bool isRedundant = true;
                while(st.top()!='('){
                    char top = st.top();
                    if(top =='+'||top =='-'||top =='/'||top =='*'){
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant==true)
                        return true;
                    st.pop();
            }
        }
    }
    return false;
}
