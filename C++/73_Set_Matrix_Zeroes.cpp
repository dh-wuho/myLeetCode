class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int height = matrix.size();
        if(height == 0) {
            return;
        }
        int width = matrix[0].size();
        bool colZero = false;
        bool rowZero = false;
        
        for(int i = 0; i < height; i++) {
            if(matrix[i][0] == 0) {
                colZero = true;
            }
        }
        
        for(int i = 0; i < width; i++) {
            if(matrix[0][i] == 0) {
                rowZero = true;
            }
        }
        
        for(int i = 1; i < height; i++) {
            for(int j = 1; j < width; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < height; i++) {
            for(int j = 1; j < width; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] =0;
                }
            }
        }
        
        if(colZero) {
            for(int i = 0; i < height; i++) {
                matrix[i][0] = 0;
            }
        }
        
        if(rowZero) {
            for(int i = 0; i < width; i++) {
                matrix[0][i] = 0;
            }
        }
    }
};