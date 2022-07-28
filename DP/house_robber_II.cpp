#define ll long long
ll solve(vector<int> &arr)
{
    ll n = arr.size();
    ll prev1 = arr[0];
    ll prev2 = max( arr[1] , arr[0]);
    ll ans;
    for(int i = 2; i < n ; i++)
    {
        ans = max(prev1 + arr[i], prev2 + 0);
        prev1 = prev2;
        prev2 = ans;
    }
    return prev2;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    ll n = valueInHouse.size();
    if(n == 1) return valueInHouse[0];
    if(n == 2) return max(valueInHouse[0], valueInHouse[1]);
    vector<int> first,second;
    for(int i = 0; i < n; i++)
    {
        if(i != 0) first.push_back(valueInHouse[i]);
        if(i != n-1) second.push_back(valueInHouse[i]);
    }
    return max(solve(first),solve(second));
}