class Solution {
  public:
    int isItPossible(string S, string T, int M, int N) {
        // code here
        if (M != N) return 0;
        
        int a = 0, b = 0;
        
        for(int i = 0; i < N; i++)
        {
            if(S[i] == 'A') a++;
            else if(S[i] == 'B') b++;
            
            if(T[i] == 'A') a--;
            else if(T[i] == 'B') b--;
        }
        
        if(a || b) return 0;
        
        int first = 0;
        int second = 0;
        
        while(first < M && second < N)
        {
            while(S[first] == '#' && first < M) first++;
            while(T[second] == '#' && second < N) second++;
            
            if(S[first] != T[second]) return 0;
            
            if(S[first] == 'A' && first < second) return 0;
            if(S[first] == 'B' && first > second) return 0;
            
            first++;
            second++;
        }
        
        return 1;
    }
};