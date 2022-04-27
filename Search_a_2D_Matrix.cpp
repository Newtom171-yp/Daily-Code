class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0;
        int rowCount = matrix.size();
        int colCount = matrix[0].size();
        int last = rowCount*colCount - 1;
        int mid = last + (start - last)/2;
        while(start <= last){
            int midElement = matrix[mid/colCount][mid%colCount];
            if( midElement == target) return true;
            if(target < midElement) last = mid - 1;
            else start = mid + 1;
            mid = last + (start - last)/2;
        }
        return false;
    }
};