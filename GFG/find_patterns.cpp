class Solution{   
public:
    int numberOfSubsequences(string S, string W){
        // code here 
        int ans = 0;
        vector<bool> vis(S.length());
        for(int i = 0; i < S.length(); i++)
        {
            if(S[i] == W[0] && !vis[i])
            {
                vis[i] = true;
                int j = i+1;
                int k = 1;
                while(j < S.length() && k < W.length())
                {
                    if(S[j] == W[k] && !vis[j])
                    {
                        vis[j] = true;
                        k++;
                    }
                    j++;
                }
                
                if(k == W.length())
                {
                    ans++;
                }
                else break;
            }
        }
    return ans;
    }
};