/***                                                *
 * 1. Brute Force                                   *                              
 * Time complexity: O(m * n)                        *
 * Space complexity: O(m)                         ***/


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        if(findNums.size() == 0 || nums.size() == 0) {
            return res;
        }
        
        for(int i = 0; i < findNums.size(); i++) {
            int j;
            for(j = 0; j < nums.size(); j++) {
                if(findNums[i] == nums[j]) {
                    break;
                }
            }
            for(j = j + 1; j < nums.size(); j++) {
                if(findNums[i] < nums[j]) {
                    res.push_back(nums[j]);
                    break;
                }
            }
            if(res.size() < i + 1) {
                res.push_back(-1);
            }
        }
        
        return res;
    }
};

/***                                                *
 * 1. Brute Force                                   *                              
 * Time complexity: O(m + n)                        *
 * Space complexity: O(m + n)                     ***/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> stk;
        unordered_map<int, int> myMap;
        vector<int> res;
        
        for(int i = 0; i < nums.size(); i++) {
            while(!stk.empty() && nums[i] > stk.top()) {
                myMap.emplace(stk.top(), nums[i]);
                stk.pop();
            }
            stk.emplace(nums[i]);
        }
        
        while(!stk.empty()) {
            myMap.emplace(stk.top(), -1);
            stk.pop();
        }
        
        for(int i = 0; i < findNums.size(); i++) {
            res.push_back(myMap[findNums[i]]);
        }
        
        return res;
    }
};