// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    long solve(vector<int> &points,long n, long index, vector<long> & dp)
    {
        if(index > n) return 0;
        
        if(dp[index] != -1) return  dp[index];
        
        return dp[index] = points[index-1] + solve(points,n,index+points[index-1],dp);
    }
    
    long maxScore(vector<int> points) {
        // Code Here
        long n = points.size();
        
        long ans = -1;
        
        vector<long> dp(n + 1,-1);
        
        for(long i = 1; i <= n; i++)
        {
            ans = max(ans,solve(points,n,i,dp));
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i];
        }

        Solution obj;

        long ans = obj.maxScore(points);

        cout << ans << endl;
    }
}  // } Driver Code Ends