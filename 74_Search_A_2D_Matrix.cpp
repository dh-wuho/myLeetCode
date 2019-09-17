class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int height = matrix.size();
        if(height == 0) {
            return false;
        }
        int width = matrix[0].size();
        
        int i = height - 1;
        int j = 0;
        while(i > -1 && j < width) {
            if(matrix[i][j] == target) {
                return true;
            }
            if(matrix[i][j] > target) {
                i--;
            }
            else {
                j++;
            }
        }
        
        return false;
    }
};



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int height = matrix.size();
        if(height == 0) {
            return false;
        }
        int width = matrix[0].size();
        
        int start = 0;
        int end = height * width - 1;
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            int row = mid / width;
            int col = mid % width;
            if(matrix[row][col] == target) {
                return true;
            }
            if(matrix[row][col] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return false;
    }
};