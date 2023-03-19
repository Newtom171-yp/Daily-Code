class Solution {
  public:
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        // code here
        vector<int> left(N,0);
        vector<int> right(N,0);
        vector<int> ans;
        set<int> s;
        set<int> s1;
        int dist_element = 0;
        
        for(int i = 0; i < N; i++)
        {
            if(s.find(A[i]) != s.end()) dist_element++;
            else s.insert(A[i]);
            
            left[i] = dist_element;
        }
        
        dist_element = 0;
        
        for(int i = N-1; i >= 0; i--)
        {
            if(s1.find(A[i]) != s1.end()) dist_element++;
            else s1.insert(A[i]);
            
            right[i] = dist_element;
        }
        
        for(int i = 0; i < N; i++)
        {
            ans[i] = left[i] - right[i];
        }
        
        return ans;
    }
};