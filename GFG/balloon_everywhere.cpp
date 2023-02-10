class Solution{
public:
    int maxInstance(string s){
        vector<int> alpha(26,0);
        int ans = 0;
        for(int i = 0; i < s.length(); i++)
        {
            alpha[s[i] -'a']++;
        }
        
        ans = min({alpha['b' - 'a'], alpha['a' - 'a'], alpha['l' - 'a']/2, alpha['o' - 'a']/2, alpha['n'-'a']});
        return ans;
    }
};