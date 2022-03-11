/*

Given a keypad as shown in the diagram, and an N digit number which is represented by array a[ ],
the task is to list all words which are possible by pressing these numbers.

Example 1:

Input: N = 3, a[] = {2, 3, 4}
Output:
adg adh adi aeg aeh aei afg afh afi 
bdg bdh bdi beg beh bei bfg bfh bfi 
cdg cdh cdi ceg ceh cei cfg cfh cfi 
Explanation: When we press 2,3,4 then 
adg, adh, adi, ... cfi are the list of 
possible words.

Example 2:

Input: N = 3, a[] = {3, 4, 5}
Output:
dgj dgk dgl dhj dhk dhl dij dik dil 
egj egk egl ehj ehk ehl eij eik eil 
fgj fgk fgl fhj fhk fhl fij fik fil
Explanation: When we press 3,4,5 then 
dgj, dgk, dgl, ... fil are the list of 
possible words.

*/

void solve(int a[], string output, int index, string mapping[],vector<string>&ans, int n)
    {
        if(index >= n)
        {
            ans.push_back(output);
            return;
        }
        
        int number = a[index];
        string value = mapping[number];
        
        for(int i =0;i<value.length();i++)
        {
            output +=value[i];
            solve(a,output,index+1,mapping,ans,n);
            output.pop_back();
        }
        
    }
    
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> ans;
        string output="";
        int index =0;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(a,output,index,mapping,ans,N);
        return ans;
    }
