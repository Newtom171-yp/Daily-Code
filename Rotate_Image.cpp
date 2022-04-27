class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //transposing the matrix
        int m = matrix.size();
        for(int i = 0; i < m; i++){
            for(int j = i; j < m; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        //reverse the matrix
        for(int i = 0; i < m; i++){
            int l = 0, r = m-1;
            while(l < r){
                swap(matrix[i][l++],matrix[i][r--]);
            }
        }
    }
};