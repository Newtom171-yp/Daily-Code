//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    long long solve(int dice, int face, int target)
    {
        if(target<0) return 0;
        
        if(dice == 0 && target != 0) return 0;
        
        if(target == 0 && dice != 0) return 0;
        
        if(dice == 0 && target == 0) return 1;
        
        long long ans = 0;
        
        for(int i = 1; i <= face; i++)
        {
            ans = ans + solve(dice-1, face, target - i);
        }
        
        return ans;
        
    }
    
    long long solveMem(int dice, int face, int target, vector<vector<long long>> &dp)
    {
        if(target<0) return 0;
        
        if(dice == 0 && target != 0) return 0;
        
        if(target == 0 && dice != 0) return 0;
        
        if(dice == 0 && target == 0) return 1;
        
        long long ans = 0;
        
        if(dp[dice][target] != -1) return dp[dice][target];
        
        for(int i = 1; i <= face; i++)
        {
            ans = ans + solveMem(dice-1, face, target - i,dp);
        }
        
        return dp[dice][target] = ans;
        
    }
    
    long long solveTab(int dice, int face, int target)
    {
        vector<vector<long long>> dp(dice + 1, vector<long long>(target + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= dice; i++)
        {
            for(int j = 1; j <= target; j++)
            {
                long long ans = 0;
                for(int k = 1; k <= face; k++)
                {
                    if(j - k >= 0)
                    ans = ans + dp[i-1][j - k];
                }
                
                dp[i][j] = ans;
            }
        }
        
        return dp[dice][target];
    }
    
    
    long long solveOpt(int dice, int face, int target)
    {
        
        vector<long long> prev(target+1, 0);
        vector<long long> curr(target+1, 0);
        
        prev[0] = 1;
        for(int i = 1; i <= dice; i++)
        {
            for(int j = 1; j <= target; j++)
            {
                long long ans = 0;
                for(int k = 1; k <= face; k++)
                {
                    if(j - k >= 0)
                    ans = ans + prev[j - k];
                }
                
                curr[j] = ans;
            }
            prev = curr;
        }
        
        return prev[target];
    }
    
    long long noOfWays(int M , int N , int X) {
        // code here
        // return solve(N,M,X);
        
        // vector<vector<long long>> dp(N + 1, vector<long long>(X + 1, -1));
        
        // return solveMem(N,M,X,dp);
        
        // return solveTab(N,M,X);
        
        return solveOpt(N,M,X);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends