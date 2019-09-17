// O(m+n)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int R = matrix.size();        
        if(R == 0) {
            return false;
        }
        int C = matrix[0].size();
        
        int r = R - 1;
        int c = 0;
        
        while(r > -1 && c < C) {
            if(matrix[r][c] == target) {
                return true;
            }
            if(matrix[r][c] < target) {
                c++;
            }
            else {
                r--;
            }
        }
        return false;
    }
};