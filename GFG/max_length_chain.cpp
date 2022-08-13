class Solution{
public:
    /*You are required to complete this method*/
    static bool comp(val &a, val &b)
    {
        return (a.second < b.second);
    }
    int maxChainLen(struct val p[],int n){
        //Your code here
        sort(p, p+n, comp);
        int ans = 1;
        int prev = p[0].second;
        for(int i = 1; i < n; i++)
        {
            if(p[i].first > prev)
            {
                prev = p[i].second;
                ans++;
            }
        }
        return ans;
    }
};