//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solveRec(int n, int k)
    {
        if(k == 1 || k == 0) return k;
        
        if(n == 1) return k;
        
        int mini = INT_MAX;
        
        
        int floorNum;
        
        for( floorNum = 1; floorNum <= k; floorNum++)
        {
            mini = min(mini, max(solveRec(n - 1, floorNum - 1), solveRec(n,k - floorNum)));
        }
        
        return mini + 1;
    }
    
    int solveMem(int n, int k, vector<vector<int>> &dp)
    {
        if(k == 1 || k == 0) return k;
        
        if(n == 1) return k;
        
        int mini = INT_MAX;
        
        if(dp[n][k] != -1) return dp[n][k];
        
        int floorNum;
        
        for( floorNum = 1; floorNum <= k; floorNum++)
        {
            mini = min(mini, max(solveMem(n - 1, floorNum - 1, dp), solveMem(n,k - floorNum, dp)));
        }
        
        return dp[n][k] = mini + 1;
    }
    
    int solveTab(int n , int k)
    {
        vector<vector<int>> dp(n + 1,vector<int>(k+1, 0));
        
        for(int i = 1; i <= n; i++)
        {
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        
        for(int i = 1; i <= k; i++)
        {
            dp[1][i] = i;
        }
        
        for(int i = 2; i <= n; i++)
        {
            for(int j = 2; j <= k; j++)
            {
                dp[i][j] = INT_MAX;
                for(int floorNum = 1; floorNum <= k; floorNum++)
                {
                    dp[i][j] = min(dp[i][j],1 + max(dp[i - 1][floorNum - 1], dp[i][j - floorNum]));
                }
            }
        }
        return dp[n][k];
    }
    
    int eggDrop(int n, int k) 
    {
        // your code here
        // return solveRec(n,k);
        // vector<vector<int>> dp(n + 1,vector<int>(k+1, -1));
        // return solveMem(n,k,dp);
        
        return solveTab(n,k);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends