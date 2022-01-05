/***                                                *
 * Binary Search                                    *
 * Time complexity: O(log(n+m)).                    * 
 * Space complexity: O(1).                        ***/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        if(m > n) {
            nums1.swap(nums2);
            m = nums1.size();
            n = nums2.size();
        }
        
        int halflen = (m + n + 1) / 2;
        int start = 0;
        int end = m;
        int left_max;
        int right_min;
        while(start <= end) {
            int i = (end + start) / 2;  
            int j = halflen - i;
            if(i < end && nums1[i] < nums2[j - 1]) {
                start = i + 1;
            }
            else {
                if(i > start && nums1[i - 1] > nums2[j]) {
                    end = i - 1;
                }
                else {
                    if(i == 0) {
                        left_max = nums2[j - 1];
                    }
                    else if(j == 0) {
                        left_max = nums1[i - 1];
                    }
                    else {
                        left_max = max(nums1[i - 1], nums2[j - 1]);
                    }
                    if((m + n) % 2 == 1) {
                        return left_max;
                    }
                    
                    if(i == m) {
                        right_min = nums2[j];
                    }
                    else if(j == n) {
                        right_min = nums1[i];
                    }
                    else {
                        right_min = min(nums1[i], nums2[j]);
                    }
                    
                    return (right_min + left_max) / 2.0;
                }
            }
        }
        return 0.0;
    }
};