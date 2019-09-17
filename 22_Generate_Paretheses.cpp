class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, "", 0, 0, n);
        return res;
    }
    
    void helper(vector<string>& res, string curr, int open, int close, int max) {
        if(curr.size() == max * 2) {
            res.push_back(curr);
        }
        
        if(open < max) {
            helper(res, curr + '(', open + 1, close, max);
        }
        if(close < open) {
            helper(res, curr + ')', open, close + 1, max);
        }
    }
    
};