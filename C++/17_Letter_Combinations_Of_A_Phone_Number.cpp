class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> res;
        if(digits.size() == 0) {
            return res;
        }
        
        vector<string> table = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string oneRes = "";
  
        reverse(digits.begin(), digits.end());
        int input = stoi(digits);
        
        combinationsHelper(table, input, oneRes, res);
        
        return res;
    }
    
    void combinationsHelper(vector<string>& table, int currNum, string& oneRes, vector<string>& res) {
        
        if(currNum == 0) {
            res.push_back(oneRes);
            return;
        }
        
        int currIndex = currNum % 10 - 2;
        
        for(int i = 0; i < table[currIndex].size(); i++) {
            oneRes.push_back(table[currIndex].at(i));
            combinationsHelper(table, currNum / 10, oneRes, res);
            oneRes.pop_back();
        }
    }
};