/*
You have been given two strings 'STR1' and 'STR2'. 
You have to find the length of the longest common substring.
A string “s1” is a substring of another string “s2” if “s2” contains
the same characters as in “s1”, in the same order and in continuous fashion also.
*/

//Same as the LCS problem with a slight change
int lcs(string &s1, string &s2){
	int n = s1.size();
    int m = s2.size();
    
    vector<int> prev(m+1,0), cur(m+1,0);

    int ans = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                int val = 1 + prev[j-1];
                cur[j] = val;
                ans = max(ans,val);
            }
            else
                cur[j] = 0;
        }
        prev=cur;
    }
    
    return ans;
    
}
