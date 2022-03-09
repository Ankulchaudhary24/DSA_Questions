/*

You are given a string 'STR'. The string contains [a-z] [A-Z] [0-9] [special characters].
You have to find the reverse of the string.

Sample Input 1:
3
abcde
coding
hello1

Sample Output 1:
edcba
gnidoc
1olleh

*/

//RecursiveApproach
void solve(string &str,int i, int j){
    if(i>j)
        return;
    swap(str[i],str[j]);
    i++;
    j--;
    solve(str,i,j);
    
}
string reverseString(string str)
{
	solve(str,0,str.length()-1);
    return str;
}
