int mex(vector<int> a, int k)
{
	// Write your code here
    int n = a.size();
    int* count = new int[k];
    memset(count,0,k);
    for(int i = 0; i < n; i++)
    {
        a[i] %= k;
        count[a[i]]++;
    }
    int mini = INT_MAX;
    int index;
    for(int i = 0; i < k; i++)
    {
        if(count[i]<mini)
        {
            mini = count[i];
            index = i;
        }
    }
    return (index + mini*k);
}