class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid)
    {
        return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j]);
    }
    
    void dfs(int i, int j, vector<vector<int>>& grid, int n, int m, int & area)
    {
        area++;
        grid[i][j] = 0;
        
        //North
        if(isValid(i - 1, j, n, m, grid))
        {
            dfs(i - 1, j, grid, n, m, area);
        }
        
        //East
        if(isValid(i, j + 1, n, m, grid))
        {
            dfs(i, j + 1, grid, n, m, area);
        }
        
        //West
        if(isValid(i, j - 1, n, m, grid))
        {
            dfs(i, j - 1, grid, n, m, area);
        }
        
        //South
        if(isValid(i + 1, j, n, m, grid))
        {
            dfs(i + 1, j, grid, n, m, area);
        }
        
        //North-East
        if(isValid(i - 1, j + 1, n, m, grid))
        {
            dfs(i - 1, j + 1, grid, n, m, area);
        }
        
        //South-East
        if(isValid(i + 1, j + 1, n, m, grid))
        {
            dfs(i + 1, j + 1, grid, n, m, area);
        }
        
        //North-West
        if(isValid(i - 1, j - 1, n, m, grid))
        {
            dfs(i - 1, j - 1, grid, n, m, area);
        }
        
        //South-West
        if(isValid(i + 1, j - 1, n, m, grid))
        {
            dfs(i + 1, j - 1, grid, n, m, area);
        }
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    int area = 0;
                    dfs(i, j, grid, n, m, area);
                    ans = max(ans, area);
                };
            }
        }
        return ans;
    }
};