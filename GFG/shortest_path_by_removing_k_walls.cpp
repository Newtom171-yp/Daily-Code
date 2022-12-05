class Solution {
  public:
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        // code here
        vector<vector<int>> direction{{1,0}, {0,1}, {-1,0}, {0, -1}};
        vector<vector<int>> v(n, vector<int>(m, INT_MIN));
        
        
        queue<vector<int>> q;
        
        if(mat[0][0] == 1){
            q.push({0,0, k-1});
            v[0][0] = k-1;
        }
        
        else
        {
            q.push({0,0,k});
            v[0][0] = k;
        }
        
        int count = 0;
        while(!q.empty())
        {
            int p = q.size();
            while(p--)
            {
                auto it = q.front();
                q.pop();
                if(it[0] == n-1 && it[1] == m-1)
                {
                    return count;
                }
                
                for(auto i : direction)
                {
                    int nx = it[0] + i[0];
                    int ny = it[1] + i[1];
                    int c = it[2];
                    
                    if(nx >= 0 && ny >= 0 && nx < n && ny < m)
                    {
                        if(v[nx][ny] < c)
                        {
                            if(mat[nx][ny] == 0)
                            {
                                q.push({nx,ny,c});
                                v[nx][ny] = c;
                            }
                            
                            else if(c > 0)
                            {
                                q.push({nx, ny, c-1});
                                v[nx][ny] = c-1;
                            }
                        }
                    }
                }
            }
                count++;
        }
            return -1;
    }
};