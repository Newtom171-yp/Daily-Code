class Solution{
    public:
    bool isScramble(string S1, string S2){
        //code here
        if(S1.length() != S2.length()) return false;
        if(S1 == S2) return true;
        
        int n = S1.length();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n+1, false)));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(S1[i] == S2[j]) dp[i][j][1] = true;
            }
        }
        
        for(int k = 2; k <= n; k++)
        {
            for(int i = 0; i <= n-k; i++)
            {
                for(int j = 0; j <= n-k; j++)
                {
                    for(int p = 1; p < k; p++)
                    {
                        if((dp[i][j][p] && dp[i+p][j+p][k-p]) || (dp[i][j+k-p][p] && dp[i+p][j][k-p]))
                        {
                            dp[i][j][k] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }    
};