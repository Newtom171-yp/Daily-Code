int LoneMonster(int n, int h, vector<int>&b, vector<int>&d) {
	// Write your code here.
    multimap<int,int,greater<int>> m;
    for(int i = 0; i < n; i++)
    {
        m.insert(pair<int, int>(d[i], b[i]));
    }
    int count = 0;
    for(auto i : m)
    {
        for(int it = 1; it <= i.second && h >= 0; it++)
        {
            h -= i.first;
            count++;
        }
        if(h < 0) break;
    }
    if(h >= 0) return -1;
    return count;
}