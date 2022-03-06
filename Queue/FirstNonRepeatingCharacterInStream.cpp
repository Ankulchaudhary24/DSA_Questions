/*
Given an input stream of A of n characters consisting only of lower case alphabets.
The task is to find the first non repeating character, each time a character is inserted to the stream.
If there is no such character then append '#' to the answer.

Example 1:

Input: A = "aabc"
Output: "a#bb"
Explanation: For every character first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - first non-repeating character is 'b'
*/

string FirstNonRepeating(string A){
		     int count[26];  //Array that stores the count of the letters that traversed till the point
  
		     string ans="";
  
		     for(int i=0;i<26;i++){  // Initialising the count value of all the letters to the 0
		         count[i]=0;
		     }
  
		     queue<char> q;
		     
		     for(int i=0;i<A.length();i++){ //Traversing the String or Stream
           
		         count[A[i]-'a']++; // Increasing the count of the character encountered
		         q.push(A[i]);   //Pushing the current character in queue
		         
		         while(!q.empty())
		         {
		            if(count[q.front()-'a'] == 1)
		            {
		                 ans +=q.front();
		                 break;
		            }
		            else
		                 q.pop();
		         }
           
		         if(q.empty())
		         {
		             ans +='#';
		         }
		     }
		     return ans;
		}
