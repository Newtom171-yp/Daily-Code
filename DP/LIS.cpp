//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    
    int solve(int n, int a[], int curr, int prev)
    {
        if(curr == n) return 0;
        
        //include
        int include = 0;
        if(prev == -1 || a[curr] > a[prev]) include = 1 + solve(n,a,curr+1,curr);
        
        //exclude
        int exclude = 0 + solve(n,a,curr+1,prev);
        
        return max(include, exclude);
        
    }
    
    int solveMem(int n, int a[], int curr, int prev, vector<vector<int>> &dp)
    {
        if(curr == n) return 0;
        
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
        
        //include
        int include = 0;
        if(prev == -1 || a[curr] > a[prev]) include = 1 + solveMem(n,a,curr+1,curr,dp);
        
        //exclude
        int exclude = 0 + solveMem(n,a,curr+1,prev,dp);
        
        return dp[curr][prev+1] = max(include, exclude);
        
    }
    
    int solveTab(int n, int a[])
    {
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
        for(int curr = n-1; curr >= 0; curr--)
        {
            for(int prev = curr-1; prev >= -1; prev--)
            {
                int include = 0;
                if(prev == -1 || a[curr] > a[prev]) include = 1 + dp[curr+1][curr+1];
                
                //exclude
                int exclude = 0 + dp[curr+1][prev+1];
                
               dp[curr][prev+1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
    
    int solveOpt(int n, int a[])
    {
        vector<int> currRow(n+1, 0);
        vector<int> next(n+1, 0);
        
        for(int curr = n-1; curr >= 0; curr--)
        {
            for(int prev = curr-1; prev >= -1; prev--)
            {
                int include = 0;
                if(prev == -1 || a[curr] > a[prev]) include = 1 + next[curr+1];
                
                //exclude
                int exclude = 0 + next[prev+1];
                
               currRow[prev+1] = max(include, exclude);
            }
            next = currRow;
        }
        return next[0];
    }
    
    int solveBinarySearch(int n, int a[])
    {
        if(n == 0)
        return 0;
        
        vector<int> ans;
        
        ans.push_back(a[0]);
        
        for(int i = 1; i < n; i++)
        {
            if(a[i] > ans.back()) ans.push_back(a[i]);
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[index] = a[i];
            }
        }
        return ans.size();
    }
    
    int longestSubsequence(int n, int a[])
    {
       // your code here
        //   return solve(n,a,0,-1);
    
        // vector<vector<int>> dp(n,vector<int>(n+1, -1));
        // return solveMem(n,a,0,-1,dp);
        // return solveTab(n, a)
        // return solveOpt(n,a);
        
        return solveBinarySearch(n,a);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends