class Solution {
	public:
		int CountWays(string str){
		    // Code here
		    int MOD = 1000000007;
		    vector<int> dp(str.length());
		    dp[0] = 1;
		    
		    for(int i = 1; i < dp.size(); i++)
		    {
		        if(str[i-1] == '0' && str[i] == '0'){
		            dp[i] = 0;
		        }
		        else if(str[i-1] == '0' && str[i] != '0'){
		            dp[i] = (dp[i-1])%MOD;
		        }
		        else if(str[i-1] != '0' && str[i] == '0'){
		            if(str[i-1] == '1' || str[i-1] == '2')
		            {
		                dp[i] = (i >= 2 ? dp[i-2] : 1)%MOD;
		            }
		            else {
		                dp[i] = 0;
		            }
		        }
		        else{
		            if(stoi(str.substr(i-1, 2)) <= 26)
		            {
		                dp[i] = (dp[i-1])%MOD + (i >= 2 ? dp[i-2] : 1)%MOD;
		            }
		            else
		            {
		                dp[i] = (dp[i-1])%MOD;
		            }
		        }
		    }
		    return (dp[str.length() - 1])%MOD;
		}

};