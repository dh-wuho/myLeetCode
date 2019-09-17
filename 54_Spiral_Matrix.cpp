class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int height = matrix.size();
        vector<int> res;
        if(height == 0) {
            return res;
        }
        int width = matrix[0].size();
        
        int left = 0;
        int right = width - 1;
        int top = 0;
        int bottom = height - 1;
        
        while(left <= right && top <= bottom) {
            for(int i = left; i < right + 1; i++) {
                res.push_back(matrix[top][i]);
            }
            for(int i = top + 1; i < bottom + 1; i++) {
                res.push_back(matrix[i][right]);
            }
            if(left < right && top < bottom) {
                for(int i = right - 1; i > left - 1; i--) {
                    res.push_back(matrix[bottom][i]);
                }
                for(int i = bottom - 1; i > top; i--) {
                    res.push_back(matrix[i][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        
        return res;
    }
};