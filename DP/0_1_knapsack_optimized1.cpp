int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int>> dp(n,vector<int> (maxWeight+1, 0));
    
    vector<int> prev(maxWeight+1, 0);
    vector<int> curr(maxWeight+1, 0);
    
    for(int i = weight[0]; i <= maxWeight; i++)
    {
        if(weight[0] > maxWeight) prev[i] = 0;
        else prev[i] = value[0];
    }
    
    for(int index = 1; index < n; index++)
    {
        for(int w = 0; w <=maxWeight; w++)
        {
            int include = 0, exclude = 0;
            if(weight[index] <= w)
            {
                include = value[index] + prev[w-weight[index]];
            }
            exclude = prev[w];
            curr[w] = max(include,exclude);
        }
        prev = curr;
    }
    return prev[maxWeight];
}