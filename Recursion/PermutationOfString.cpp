/*

Given a string S. The task is to print all permutations of a given string in lexicographically sorted order.

 

Example 1:

Input: ABC
Output:
ABC ACB BAC BCA CAB CBA
Explanation:
Given string ABC has permutations in 6 
forms as ABC, ACB, BAC, BCA, CAB and CBA .

Example 2:

Input: ABSG
Output:
ABGS ABSG AGBS AGSB ASBG ASGB BAGS 
BASG BGAS BGSA BSAG BSGA GABS GASB 
GBAS GBSA GSAB GSBA SABG SAGB SBAG 
SBGA SGAB SGBA
Explanation:
Given string ABSG has 24 permutations.

*/

void solve(string str, int index, vector<string> &ans)
	    {
	        if(index >= str.length())
	        {
	            ans.push_back(str);
	            return;
	        }
	        
	        for(int i=index;i<str.length();i++)
	        {
	            swap(str[i],str[index]);
	            solve(str,index+1,ans);
	            swap(str[i],str[index]);
	        }
	        
	    }
	
		vector<string> find_permutation(string str)
		{
		    vector<string> ans;
		    int index =0;
		    solve(str,index,ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
