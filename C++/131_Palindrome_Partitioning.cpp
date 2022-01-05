class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        if(s.size() == 0) {
            return res;
        }
        
        vector<string> currRes;
        backTrack(s, 0, currRes, res);
        return res;
    }
    
    void backTrack(string s, int index, vector<string> currRes, vector<vector<string> >& res) {
        if(index == s.size()) {
            res.push_back(currRes);
            return;
        }
        
        for(int i = index; i < s.size(); i++) {
            if(isPalindrome(s, index, i)) {
                currRes.push_back(s.substr(index, i - index + 1));
                backTrack(s, i + 1, currRes, res);
                currRes.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int start ,int end) {
        if(start == end) {
            return true;
        }
        while(start < end) {
            if(s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        
        return true;
    }
};