/***                                                *
 * 1. Binary                                        *                              
 * Time complexity: O(log n)                        *
 * Space complexity:                              ***/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        
        int start = 0;
        int end = A.size();
        
        while(start < end) {
            int mid = start + (end - start) / 2;
            
            if(A[mid] < A[mid + 1]) {
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }
        
        return start;
    }
};