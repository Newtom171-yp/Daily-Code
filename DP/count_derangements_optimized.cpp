#define MOD 1000000007
#define ll long long

long long int countDerangements(int n) 
{
    // Write your code here.
    ll prev1 = 0;
    ll prev2 = 1;
    
    for(int i = 3; i <= n; i++)
    {
        ll first = prev1%MOD;
        ll second = prev2%MOD;
        ll sum = (first + second)%MOD;
        ll multi = (i-1)%MOD;
        ll ans = (multi*sum)%MOD;
        prev1 = prev2;
        prev2 = ans;
    }
    return prev2;
}