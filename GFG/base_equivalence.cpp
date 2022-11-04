class Solution {
  public:
    
    int cal_log(int n, int mid)
    {
        int ans = 0;
        
        while(n>0)
        {
            ans++;
            n/=mid;
        }
        return ans;
    }
    
    string baseEquiv(int n, int m){
        // code here
        int s = 2;
        int e = 32;
        int mid = s + (e - s)/2;
        
        while(s <= e)
        {
            int res = cal_log(n,mid);
            if(res == m) return "Yes";
            else if(res > m) s = mid + 1;
            else e = mid - 1;
            mid = s + (e - s)/2;
        }
        
        return "No";
    }
};