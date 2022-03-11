/*
You are given a string 'STR' containing lowercase English letters from a to z inclusive.
Your task is to find all non-empty possible subsequences of 'STR'.

Sample Input 1:
1 
abc
Sample Output 1:
a ab abc ac b bc c

*/

void powerSet(string nums, string output, int index,vector<string> &ans)
{
    if(index >= nums.size()){
        if(output.length() >0){
            ans.push_back(output); 
        }
        return;
    }
    powerSet(nums,output,index+1,ans);
    char elements = nums[index];
    output += elements;
    powerSet(nums,output,index+1,ans);
}

vector<string> subsequences(string str){
	vector<string> ans;
    string output;
    int index = 0;
    powerSet(str,output,index,ans);
    return ans;
}
