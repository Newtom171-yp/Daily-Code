class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isPossible(int node, bool graph[101][101], int currentColor, int n, int color[])
    {
        for(int i = 0; i < n; i++)
        {
            if(i != node && graph[i][node] == 1 && color[i] == currentColor) return false;
        }
        return true;
    }
    
    bool solve(int node, bool graph[101][101], int m, int n, int color[])
    {
        if(node == n) return true;
        
        for(int i = 1; i <= m; i++)
        {
            if(isPossible(node, graph, i, n, color))
            {
                color[node] = i;
                
                if(solve(node+1,graph,m,n,color)) return true;
                
                color[node] = 0;
            }
        }
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        
        int color[n] = {0};
        
        return solve(0,graph,m,n,color);
    }
};