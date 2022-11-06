class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int> ans;
        vector<int> notes = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        vector<int> quant(10,0);
        
        for(int i = 0; i < 10; i++)
        {
            quant[i] = N/notes[i];
            N = N % notes[i];
        }
        
        for(int i = 0;  i < 10; i++)
        {
            for(int j = 0; j < quant[i]; j++)
            {
                ans.push_back(notes[i]);
            }
        }
        
        return ans;
    }
};