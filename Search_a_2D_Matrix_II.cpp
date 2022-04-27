class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowCount = matrix.size();
        int colCount = matrix[0].size();
        int col = colCount - 1;
        int row = 0;
        while(row < rowCount && col >=0){
            int elem = matrix[row][col];
            if(elem == target) return true;
            if(elem > target) col--;
            else row++;
        }
        return false;
    }
};