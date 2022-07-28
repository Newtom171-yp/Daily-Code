#define MOD 1000000007
#define ll long long
#include <vector>
ll solve(ll n, vector<ll> &dp)
{
    if(n == 1) return 0;
    if(n == 2) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = (((n-1)%MOD) * ( solve(n-1,dp)%MOD + solve(n-2,dp)%MOD ))%MOD;
}

long long int countDerangements(int n) 
{
    // Write your code here.
    vector<ll> dp(n+1, -1);
    dp[1] = 0;
    dp[2] = 1;
    
    for(int i = 3; i <= n; i++)
    {
        ll first = dp[i-1]%MOD;
        ll second = dp[i-2]%MOD;
        ll sum = (first + second)%MOD;
        ll multi = (i-1)%MOD;
        dp[i] = (multi*sum)%MOD;
    }
    return dp[n];
}