int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    int dp [n+1][maxWeight+1];
    memset(dp,0,sizeof dp);
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= maxWeight; j++)
        {
            //Not Included
            dp[i][j] = dp[i-1][j];
            
            if(j >= weight[i-1])
            {
                int remain = j - weight[i-1];
                if(dp[i-1][remain] + value[i-1] > dp[i-1][j])
                {
                    dp[i][j] = dp[i-1][remain] + value[i-1];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][maxWeight];
}