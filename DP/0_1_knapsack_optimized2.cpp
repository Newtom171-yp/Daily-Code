int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int>> dp(n,vector<int> (maxWeight+1, 0));
    
    vector<int> curr(maxWeight+1, 0);
    
    for(int i = weight[0]; i <= maxWeight; i++)
    {
        if(weight[0] > maxWeight) curr[i] = 0;
        else curr[i] = value[0];
    }
    
    for(int index = 1; index < n; index++)
    {
        for(int w = maxWeight; w >= 0; w--)
        {
            int include = 0, exclude = 0;
            if(weight[index] <= w)
            {
                include = value[index] + curr[w-weight[index]];
            }
            exclude = curr[w];
            curr[w] = max(include,exclude);
        }
    }
    return curr[maxWeight];
}