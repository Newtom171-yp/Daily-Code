int solve(vector<int> &weight, vector<int> &value, int capacity, int index, vector<vector<int>> &dp)
{
    if(index == 0)
    {
        if(weight[index] > capacity) return 0;
        else return value[index];
    }
    
    if(dp[index][capacity] != -1) return dp[index][capacity];
    
    int include = 0, exclude = 0;
    if(weight[index] <= capacity)
    {
        include = value[index] + solve(weight,value, capacity-weight[index],index-1,dp);
    }
    exclude = solve(weight,value, capacity ,index-1,dp);
    
    return dp[index][capacity] = max(include, exclude);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int>> dp(n,vector<int> (maxWeight+1, -1));
    return solve(weight,value,maxWeight,n-1,dp);
}