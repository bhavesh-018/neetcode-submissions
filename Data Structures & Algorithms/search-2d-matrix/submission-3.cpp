class Solution {
public:
    bool searchInRow(vector<vector<int>>& matrix, int target, int row){
        int n = matrix[0].size();
        int start = 0, end = n-1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(target == matrix[row][mid]){
                return true;
            }else if(matrix[row][mid] > target){
                end = mid - 1; 
            }else{
                start = mid + 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
    
        int startRow = 0, endRow = m-1;
        while(startRow <= endRow){
            int midRow = startRow + (endRow - startRow) / 2;

            if(matrix[midRow][0] <= target && target <= matrix[midRow][n-1]){
                return searchInRow(matrix, target, midRow);
            }else if(matrix[midRow][n-1] < target){
                startRow = midRow + 1;
            }else if(matrix[midRow][0] > target){
                endRow = midRow - 1;
            }
        }
        return false;
    }
};
