/***                                                *
 * 1. Iteration                                     *                              
 * Time complexity: O(2^n)                          *
 * Space complexity:                              ***/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(1, vector<int>());
        
        for(int i = 0; i < nums.size(); i++) {
            int currLength = res.size();
            for( int j = 0; j < currLength; j++) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        
        return res;
    }
};

/***                                                *
 * 2. BitMap                                        *                              
 * Time complexity: O(2^n)                          *
 * Space complexity:                              ***/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res; 
        int max = 1 << nums.size();
        
        for(int i = 0; i < max; i++) {
            vector<int> tmp;
            for(int j = 0; j < nums.size(); j++) {
                if(i & (1 << j)) {
                    tmp.push_back(nums[j]);
                }
            }
            res.push_back(tmp);
        }
        
        return res;    
    }
};

/***                                                *
 * 2. Recursion                                     *                              
 * Time complexity: O(2^n)                          *
 * Space complexity:                              ***/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res; 
        vector<int> subset;
        
        subsetsHelper(nums, 0, subset, res);
        
        return res;
    }
    
    void subsetsHelper(vector<int>& nums, int start, vector<int>& subset, vector<vector<int>>& res) {
        res.push_back(subset);
        for(int i = start; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            subsetsHelper(nums, i + 1, subset, res);
            subset.pop_back();
        }   
    }
};