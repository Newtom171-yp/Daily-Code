int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int>> dp(n,vector<int> (maxWeight+1, 0));
    for(int i = weight[0]; i <= maxWeight; i++)
    {
        if(weight[0] > maxWeight) dp[0][i] = 0;
        else dp[0][i] = value[0];
    }
    
    for(int index = 1; index < n; index++)
    {
        for(int w = 0; w <=maxWeight; w++)
        {
            int include = 0, exclude = 0;
            if(weight[index] <= w)
            {
                include = value[index] + dp[index-1][w-weight[index]];
            }
            exclude = dp[index-1][w];
            dp[index][w] = max(include,exclude);
        }
    }
    return dp[n-1][maxWeight];
}