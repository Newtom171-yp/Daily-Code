#define MOD 1000000007
#define ll long long
int numberOfWays(int n, int k) {
    // Write your code here.
    ll same = k;
    ll diff = (k%MOD)*((k-1)%MOD);
    ll total = (same%MOD + diff%MOD)%MOD;
    
    for(int i = 3; i <= n; i++)
    {
        same = diff;
        diff = total * ((k-1)%MOD);
        total = (same%MOD + diff%MOD)%MOD;
    }
    return total;
}
