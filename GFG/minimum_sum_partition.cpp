class Solution{

  public:
  
    int solve(int arr[], int n, int t_sum, int sum, int index, vector<vector<int>> &dp)
    {
        if(index == n)
        {
            return abs(t_sum - 2*sum);
        }
        
        if(dp[index][sum] != -1) return dp[index][sum];
        
        int first = solve(arr,n,t_sum,sum+0,index+1,dp);
        int second = solve(arr,n,t_sum,sum+arr[index],index+1,dp);
        
        return dp[index][sum] = min(first,second);
    }
    
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    
	    for(int i = 0; i < n; i++)
	    {
	        sum += arr[i];
	    }
	    
	    vector<vector<int>> dp(n+1, vector<int>(sum+1,-1));
	    return solve(arr,n,sum,0,0,dp);
	} 
};