/***                                                *
 * 1. Recursion by using a visited vector.          *                              
 * Time complexity: O(2^n)                          *
 * Space complexity:                              ***/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> aResult;
        vector<int> visited(nums.size(), 0);
        permuteHelper(nums, visited, aResult, res);
        return res;
    }
    
    void permuteHelper(vector<int>& nums, vector<int>& visited, vector<int>& aResult, vector<vector<int>>& res) {
        if(aResult.size() == nums.size()) {
            res.push_back(aResult);
            return;
        }
        else {
            for(int i = 0; i < nums.size(); i++) {
                if(visited[i]) {
                    continue;
                }
                aResult.push_back(nums[i]);
                visited[i] = 1;
                permuteHelper(nums, visited, aResult, res);
                visited[i] = 0;
                aResult.pop_back();
            }
        }
    }
};

/***                                                *
 * 2. Recursion by swaping elements.                *                              
 * Time complexity: O(2^n)                          *
 * Space complexity:                              ***/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permuteHelper(nums, 0, res);
        return res;
    }
    
    void permuteHelper(vector<int>& nums, int start, vector<vector<int>>& res) {
        if(start == nums.size()) {
            res.push_back(nums);
            return;
        }
        
        for(int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            permuteHelper(nums, start + 1, res);
            swap(nums[start], nums[i]);
        }
    }
};