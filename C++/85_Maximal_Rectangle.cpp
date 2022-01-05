class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int h = matrix.size();
        if(h == 0) {
            return 0;
        }
        int w = matrix[0].size();
        vector<int> heights(w + 1, 0);
        int maxArea = 0;
        stack<int> stk;
        for(int i = 0; i < h; i++) {
            
            for(int j = 0; j < w + 1; j++) {
                if(j < w) {
                    if(matrix[i][j] == '1') {
                        heights[j] += 1;
                    }
                    else {
                        heights[j] = 0;
                    }
                }
                
                while(!stk.empty() && heights[j] <= heights[stk.top()]) {
                    int hIndex = stk.top();
                    stk.pop();
                    maxArea = max(maxArea, heights[hIndex] * (stk.empty() ? j : j - stk.top() - 1));
                }
                stk.push(j);
            }
            stk.pop();
        }
        
        return maxArea;
    }
};