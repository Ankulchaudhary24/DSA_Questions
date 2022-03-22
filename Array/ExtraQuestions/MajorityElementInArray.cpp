/*
Given an array A of N elements.
Find the majority element in the array.
A majority element in an array A of size N
is an element that appears more than N/2 times in the array.
 
Example 1:

Input:
N = 3 
A[] = {1,2,3} 
Output:
-1
Explanation:
Since, each element in 
{1,2,3} appears only once so there 
is no majority element.
Example 2:

Input:
N = 5 
A[] = {3,1,3,3,2} 
Output:
3
Explanation:
Since, 3 is present more
than N/2 times, so it is 
the majority element.
*/

//Appraoch 1: Using the map to count the occurence of the element O(n) space and O(n) time complexity
int majorityElement(int a[], int size)
    {
      unordered_map<int, int> eleToCount;
      
      for(int i=0;i<size;i++)
      {
          eleToCount[a[i]]++;
      }
      
      for(auto it = eleToCount.begin(); it!= eleToCount.end(); it++)
      {
          if(it->second > size/2)
          {
              return it->first;
          }
      }
      return -1;
    }

//Appraoch 2: checking the array elements adjacent (Using Moore’s Voting Algorithm):   
int findMajorityCandidate(int a[], int size)
    {
      int cnt =1;
      int majIndex = 0;
      
      for(int i=1; i<size; i++)
      {
          if(a[i] == a[majIndex])
            cnt++;
          else
            cnt--;
          
          if(cnt == 0)
           {
               majIndex = i;
               cnt =1;
           }
      }
      return a[majIndex];
    }
    
    bool isMajority(int a[],int size,int majElement)
    {
        int cnt = 0;
        for(int i =0;i<size; i++)
        {
            if(a[i]==majElement)
                cnt++;
            if(cnt >size/2)
                return true;
        }
        return false;
    }
    
    int majorityElement(int a[], int size)
    {
       int majElement =  findMajorityCandidate(a, size);
       bool isMajElement = isMajority(a, size, majElement);
       
       if(isMajElement)
        return majElement;
       else
        return -1;
    }
