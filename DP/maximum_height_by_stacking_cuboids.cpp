class Solution {
public:
    
    bool check(vector<int> a, vector<int> b)
    {
        return (b[0] <= a[0] && b[1] <= a[1] && b[2] <= a[2]);
    }
    
    int solveOpt(int n, vector<vector<int>>& a)
    {
        vector<int> currRow(n+1, 0);
        vector<int> next(n+1, 0);
        
        for(int curr = n-1; curr >= 0; curr--)
        {
            for(int prev = curr-1; prev >= -1; prev--)
            {
                int include = 0;
                if(prev == -1 || check(a[curr], a[prev])) include = a[curr][2] + next[curr+1];
                
                //exclude
                int exclude = 0 + next[prev+1];
                
               currRow[prev+1] = max(include, exclude);
            }
            next = currRow;
        }
        return next[0];
    }
    
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &a : cuboids) sort(a.begin(), a.end());
        sort(cuboids.begin(), cuboids.end());
        
        return solveOpt(cuboids.size(), cuboids);
    }
};