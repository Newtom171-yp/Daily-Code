int solve(vector<int> &weight, vector<int> &value, int capacity, int index)
{
    if(index == 0)
    {
        if(weight[index] > capacity) return 0;
        else return value[index];
    }
    
    int include = 0, exclude = 0;
    if(weight[index] <= capacity)
    {
        include = value[index] + solve(weight,value, capacity-weight[index],index-1);
    }
    exclude = solve(weight,value, capacity ,index-1);
    
    return max(include, exclude);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    return solve(weight,value,maxWeight,n-1);
}