int solve(vector<int> &nums, int n, vector<int> dp)
{
    if(n < 0) return 0;
    if(n == 0) return nums[0];
    if(dp[n] != -1) return dp[n];
    int incl = solve(nums, n-2, dp) + nums[n];
    int excl = solve(nums, n-1, dp) + 0;
    
    return dp[n] = max(incl,excl);
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
//     vector<int> dp(n,-1);
//     int ans = solve(nums, n-1, dp);
//     return ans;
    int prev1 = nums[0];
    int prev2 = max( nums[1] , nums[0]);
    int ans;
    for(int i = 2; i < n; i++)
    {
        ans = max(prev1 + nums[i], prev2 + 0);
        prev1 = prev2;
        prev2 = ans;
    }
    return prev2;
}