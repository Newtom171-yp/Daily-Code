class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    
    void dfs(vector<vector<char>>& grid, vector<vector<bool>> &visited, int i, int j)
    {
        if(grid[i][j] == 'O') return;
        if(visited[i][j]) return;
        
        visited[i][j] = true;        
        
        //up
        if(j > 0)
            dfs(grid, visited, i, j - 1);
        
        //down
        if(j < grid[0].size() - 1)
            dfs(grid, visited, i, j + 1);
        
        //left
        if(i > 0)
            dfs(grid, visited, i - 1, j);
        
        //right
        if(i < grid.size() - 1)
            dfs(grid, visited, i + 1, j);
    }
    
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        vector<vector<bool>> visited (grid.size(), vector<bool>(grid[0].size(), false));
        
        int count = 0;
        
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(!visited[i][j] && grid[i][j] == 'X')
                {
                    count++;
                    dfs(grid, visited, i, j);
                }
            }
        }
        
        return count;
    }
};