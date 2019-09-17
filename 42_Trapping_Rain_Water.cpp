class Solution {
public:
    int trap(vector<int>& height) {
        int length = height.size();
        int res = 0;
        for(int i = 1; i < length; i++) {
            int left_max = 0;
            int right_max = 0;
            for(int j = i; j > -1; j--) {
                left_max = max(left_max, height[j]);
            }
            for(int j = i; j < length; j++) {
                right_max = max(right_max, height[j]);
            }
            res += min(left_max, right_max) - height[i];
        }
        
        return res;
    }
};



class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int left = 0;
        int right = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        
        while(left < right) {
            if(height[left] < height[right]) {
                if(height[left] > leftMax) {
                    leftMax = height[left];
                }
                else {
                    res += leftMax - height[left];
                }
                left++;
            }
            else {
                if(height[right] > rightMax) {
                    rightMax = height[right];
                }
                else {
                    res += rightMax - height[right];
                }
                right--;
            }
        }
        
        return res;
    }
};