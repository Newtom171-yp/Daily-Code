class Solution {
  public:
  
    int solve(vector<int> &dp)
    {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        for(int i = 0; i < dp.size(); i++)
        {
            if(dp[i] != 0)
            {
                maxi = max(maxi, dp[i]);
                mini = min(mini, dp[i]);
            }
        }
        return maxi - mini;
    }
    
    int beautySum(string s) {
        // Your code goes here
        int ans = 0;
        int n = s.size();
        
        for(int i = 0; i < n; i++)
        {
            vector<int> dp(26,0);
            for(int j = i; j < n; j++)
            {
                dp[s[j] - 'a'] += 1;
                int diff = solve(dp);
                ans = ans + diff;
            }
        }
        
        return ans;
    }
};