//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define MOD 1000000007
#define ll long long
class Solution{
public:
    int knots(int M, int N, int K){
        // code here
        ll dp[1001][1001];
        memset(dp,0,sizeof dp);
        return ((C(M,K,dp)%MOD) * (C(N,K,dp)%MOD))%MOD;
    }
    
    ll C(ll n, ll r, ll dp[1001][1001])
    {
        if(n == r || !r) return 1;
        if(dp[n][r]) return dp[n][r];
        
        return dp[n][r] = (C(n-1,r,dp)%MOD + C(n-1,r-1,dp)%MOD)%MOD;
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int M, N, K;
        cin>>M>>N>>K;
        
        Solution ob;
        cout<<ob.knots(M, N, K)<<"\n";
    }
    return 0;
}
// } Driver Code Ends