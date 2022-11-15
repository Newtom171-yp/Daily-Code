class Solution {
  public:
    int longestPerfectPiece(int arr[], int N) {
        
        int len = 1;
        map<int,int> mp;
        int j = 0;
        for(int i = 0; i < N; i++)
        {
            mp[arr[i]]++;
            
            while((--mp.end())->first - mp.begin()->first > 1)
            {
                mp[arr[j]]--;
                
                if(mp[arr[j]]==0) mp.erase(arr[j]);
                
                j++;
            }
            len = max(len, i - j + 1);
        }
        return len;
    }
};