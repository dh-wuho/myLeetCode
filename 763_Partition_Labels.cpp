class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> lastIndex;
        for(int i = 0; i < S.size(); i++) {
            lastIndex[S[i]] = i;
        }
        
        int last = 0;
        int start = 0;
        vector<int> res;
        
        for(int i = 0; i < S.size(); i++) {
            last = max(last, lastIndex[S[i]]);
            if(i == last) {
                res.push_back(last - start + 1);
                start = i + 1;
            }
        }
        
        return res;
    }
};