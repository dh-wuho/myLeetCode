// O(n^2)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
         for(int i = 0; i < heights.size(); i++) {
             int minHeight = heights[i];
             for(int j = i; j < heights.size(); j++) {
                 minHeight = min(minHeight, heights[j]);
                 maxArea = max(maxArea, minHeight * (j - i + 1));
             }
         }
        
        return maxArea;
    }
};


// O(n)
// ref: https://www.cnblogs.com/lichen782/p/leetcode_Largest_Rectangle_in_Histogram.html


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        heights.push_back(0);
        int maxArea = 0;
        int i = 0;
        
        while(i < heights.size()) {
            if(stk.empty() || heights[i] > heights[stk.top()]) {
                stk.push(i);
                i++;
            }
            else {
                int h = stk.top();
                stk.pop();
                maxArea = max(maxArea, heights[h] * (stk.empty() ? i : (i - stk.top() - 1)));
            }
        }
        
        
        return maxArea;
    }
};