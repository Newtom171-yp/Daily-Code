class Solution {
public:

    bool valid(int x, int y, int N, vector<vector<bool>>& visited)
    {
        return (x >= 0 && x < N && y >= 0 && y < N && !visited[x][y]);
    }
    
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    pair<int,int> target = make_pair(TargetPos[0] - 1, TargetPos[1] - 1);
	    pair<int,int> curr = make_pair(KnightPos[0] - 1, KnightPos[1] - 1);
	    
	    vector<vector<bool>> visited(N, vector<bool>(N, false));
	    
	    if(curr == target) return 0;
	    
	    int steps = 0;
	    
	    queue<pair<int,int>> q;
	    q.push(curr);
	    
	    visited[curr.first][curr.second] = true;
	    
	    while(!q.empty())
	    {
	        int size = q.size();
	        steps++;
	        while(size)
	        {
	            int x = q.front().first;
	            int y = q.front().second;
	            
	            q.pop();
	            
	            int possibleX[8] = {1, 1, -1, -1, 2, 2, -2, -2};
	            int possibleY[8] = {-2, 2, -2, 2, 1, -1, 1, -1};
	            
	            for(int i = 0; i < 8; i++)
	            {
	                int newX = x + possibleX[i];
	                int newY = y + possibleY[i];
	                
	                if(newX == target.first && newY == target.second) return steps;
	                
	                if(valid(newX, newY, N, visited))
	                {
	                    visited[newX][newY] = true;
	                    q.push(make_pair(newX,newY));
	                }
	            }
	            size--;
	        }
	    }
	    
	    return steps;
	}
};