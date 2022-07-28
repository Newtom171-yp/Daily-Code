int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i < x+1; i++)
    {
        for(int j = 0; j < num.size(); j++)
        {
            if(i-num[j] >= 0 && dp[i-num[j]] != INT_MAX)
            dp[i] = min(1 + dp[i-num[j]], dp[i]);
        }
    }
    
    return ((dp[x] == INT_MAX)?-1:dp[x]);
}