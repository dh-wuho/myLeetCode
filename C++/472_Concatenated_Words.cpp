class Solution {
public:
    struct cmp {
        bool operator() (const string& a, const string& b) {
            return a.size() < b.size();
        }  
    };
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        sort(words.begin(), words.end(), cmp());
        unordered_set<string> dict;
        
        for(string word : words) {
            if(word.empty()) {
                continue;
            }
            vector<int> dp(word.size() + 1);
            dp[0] = 1;
            for(int i = 1; i < word.size() + 1; i++) {
                for(int  j = i - 1; j > -1; j--) {
                    if(dict.count(word.substr(j, i - j)) && dp[j]) {
                        dp[i] = 1;
                        break;
                    }
                }
            }    
            if(dp.back() == 1) {
                res.push_back(word);
            }
            dict.insert(word);
        }
        
        return res;
    }
};