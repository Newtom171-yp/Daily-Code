
int maxMod(int &n, int &m, vector<int> &a, vector<int> &b)
{
    int mod = m + n;
  // Write your code here
    
    int max1 = 0;
    int max2 = 0;
    int max3 = INT_MIN;
    int max4 = INT_MIN;
    
    for(int i = 0; i < n; i++)
    {
        if(a[i]%mod && a[i]>max1) max1 = a[i];
    }
    
    for(int i = 0; i < m; i++)
    {
        if(b[i]%mod && b[i]>max1) max2 = b[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        if((a[i] + max2)%mod > max2) max3 = (a[i] + max2)%mod;
    }
    
    for(int i = 0; i < m; i++)
    {
        if((b[i] + max1)%mod > max1) max4 = (b[i] + max1)%mod;
    }
    
    return max({max1, max2, max3, max4});
}