class Solution {
public:

    int solve(vector<int>&A, int n, int left, int right, vector<vector<int>>& dp)
    {
        if(left > right) return 0;
        
        if(left == right) return A[left];
        
        if(dp[left][right] != -1) return dp[left][right];
        
        int endOne = A[left] + min(solve(A,n,left+2, right, dp), solve(A,n,left+1, right-1, dp));
        
        int endTwo = A[right] + min(solve(A,n,left+1,right-1, dp), solve(A,n,left,right-2, dp));
        
        return dp[left][right] = max(endOne, endTwo);
        
    }
    
    int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
	    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
	    return solve(A,n,0, n-1, dp);
    }
};