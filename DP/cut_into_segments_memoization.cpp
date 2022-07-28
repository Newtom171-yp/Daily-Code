#include <bits/stdc++.h>
int solve(int n , int x, int y, int z, vector<int> &dp)
{
    if(!n) return 0;
    
    if(n < 0) return INT_MIN;
    if(dp[n] != -1) return dp[n];
    int a = solve(n-x,x,y,z,dp) + 1;
    int b = solve(n-y,x,y,z,dp) + 1;
    int c = solve(n-z,x,y,z,dp) + 1;
    
    return dp[n] = max({a,b,c});
}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
    vector<int> dp(n+1,-1);
    return ((solve(n,x,y,z,dp) < 0)? 0 : solve(n,x,y,z,dp));
}