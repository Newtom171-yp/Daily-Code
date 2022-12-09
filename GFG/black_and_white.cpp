long long numOfWays(int N, int M)
{
    // write code here
    
    int dx[] = {1,1,2,2,-1,-1,-2,-2};
    int dy[] = {2,-2,1,-1,2,-2,1,-1};
    
    long long mod = 1000000007;
    long long total = ( (M*N)%mod * (M*N -1)%mod) %mod;
    
    int attack = 0;
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            for(int k = 0; k <8; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                
                if(x >= 0 && x < N && y >= 0 && y < M) attack++;
            }
        }
    }
    
    return (total - attack) % mod;
}