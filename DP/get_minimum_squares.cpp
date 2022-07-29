//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int solveMem(int n, vector<int> &dp)
	{
	    if(n == 0) return 0;
	    
	    int ans = n;
	    
	    if(dp[n] != -1) return dp[n];
	    
	    for(int i = 1; i*i <= n; i++)
	    {
	        ans = min(ans, 1 + solveMem(n - (i*i), dp));
	    }
	    
	    return dp[n] = ans;
	}
	
	int solveTab(int n)
	{
	    vector<int> dp(n+1,0);
	    
	    dp[0] = 0;
	    
	    for(int i = 1; i <=n; i++)
	    {
	        int ans = i;
	        
	        for(int j = 1; j*j <= n; j++)
    	    {
    	        if(i - (j*j) >=0)
    	        ans = min(ans, 1 + dp[i - (j*j)]);
    	    }
    	    dp[i] = ans;
	    }
	    return dp[n];
	}
	
	int MinSquares(int n)
	{
	    // Code here
	    vector<int> dp(n+1, -1);
	   // return solveMem(n , dp);
	   return solveTab(n);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends