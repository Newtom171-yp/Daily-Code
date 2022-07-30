#include <bits/stdc++.h>

int solve(int n, vector<int>& days, vector<int>&cost, int index, vector<int> & dp)
{
    if(index >= n)
        return 0;
    
    if(dp[index] != -1) return dp[index];
    
    int option1 = cost[0] + solve(n,days,cost,index+1,dp);
    int i;
    
    for(i = index; i < n && days[i] < days[index] + 7; i++);
    
    int option2 = cost[1] + solve(n, days, cost, i, dp);
    
    int j;
    
    for(j = index; j < n && days[j] < days[index] + 30; j++);
    
    int option3 = cost[2] + solve(n, days, cost, j, dp);
    
    return dp[index] = min({option1,option2,option3});
    
}


int solveTab(int n, vector<int>& days, vector<int>&cost)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;
    
    for(int k = n - 1; k >= 0; k--)
    {
        int option1 = cost[0] + dp[k+1];
        int i;

        for(i = k; i < n && days[i] < days[k] + 7; i++);

        int option2 = cost[1] + dp[i];

        int j;

        for(j = k; j < n && days[j] < days[k] + 30; j++);

        int option3 = cost[2] + dp[j];
        
        dp[k] = min({option1,option2,option3});
    }
    return dp[0];
}

int solveOpt(int n, vector<int>& days, vector<int>&cost)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;
    
    for(int k = n - 1; k >= 0; k--)
    {
        int option1 = cost[0] + dp[k+1];
        int i;

        for(i = k; i < n && days[i] < days[k] + 7; i++);

        int option2 = cost[1] + dp[i];

        int j;

        for(j = k; j < n && days[j] < days[k] + 30; j++);

        int option3 = cost[2] + dp[j];
        
        dp[k] = min({option1,option2,option3});
    }
    return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    vector<int> dp(days.size(),-1);
    //return solve(n ,days, cost, 0,dp);
    //return solveTab(n,days,cost);
    return solveOpt(n,days,cost);
}