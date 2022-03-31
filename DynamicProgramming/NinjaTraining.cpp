/*
Ninja is planing this ‘N’ days-long training schedule. 
Each day, he can perform any one of these three activities.
(Running, Fighting Practice or Learning New Moves). 
Each activity has some merit points on each day. 
As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days.

Can you help Ninja find out the maximum merit points Ninja can earn?
You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity.
Your task is to calculate the maximum number of merit points that Ninja can earn.

*/

//Appraoch 1: Recursive Solution
int solve(int day, int lastTask, vector<vector<int>> &points)
{
 	if(day ==0 )
    {
        int maxi =0;
        for(int currTask = 0;currTask < 3; currTask++)
        {
            if(currTask != lastTask)
               maxi = max(maxi,points[0][currTask]); 
        }
        return maxi;
    }
    
    int maxi =0;
    for(int currTask = 0;currTask < 3; currTask++)
    {
        if(currTask != lastTask)
           {
            int point = points[day][currTask]+solve(day-1, currTask, points);
            maxi = max(maxi, point); 
           }
     }
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    return solve(n-1, 3, points);
}

//Appraoch 2: DP with the memoization
int solve(int day, int lastTask, vector<vector<int>> &points, vector<vector<int>>& dp)
{
 	if(day ==0 )
    {
        int maxi =0;
        for(int currTask = 0;currTask < 3; currTask++)
        {
            if(currTask != lastTask)
               maxi = max(maxi,points[0][currTask]); 
        }
        return maxi;
    }
    
    if(dp[day][lastTask] != -1)
        return dp[day][lastTask];
    
    int maxi =0;
    for(int currTask = 0;currTask < 3; currTask++)
    {
        if(currTask != lastTask)
           {
            int point = points[day][currTask]+solve(day-1, currTask, points, dp);
            maxi = max(maxi, point); 
           }
     }
    return dp[day][lastTask]=maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return solve(n-1, 3, points, dp);
}

//Approach 3: DP with Tabulation
int ninjaTraining(int n, vector < vector < int > > & points) {

  vector < vector < int > > dp(n, vector < int > (4, 0));

  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++) {
    for (int last = 0; last < 4; last++) {
      dp[day][last] = 0;
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          int activity = points[day][task] + dp[day - 1][task];
          dp[day][last] = max(dp[day][last], activity);
        }
      }
    }

  }

  return dp[n - 1][3];
}

//Approach 4: Dp with space optimmized
int ninjaTraining(int n, vector < vector < int > > & points) {

  vector < int > prev(4, 0);

  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++) {

    vector < int > temp(4, 0);
    for (int last = 0; last < 4; last++) {
      temp[last] = 0;
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          temp[last] = max(temp[last], points[day][task] + prev[task]);
        }
      }
    }

    prev = temp;

  }

  return prev[3];
}
