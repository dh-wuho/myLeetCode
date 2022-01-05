class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> bMax(26);
        for(int i = 0; i < B.size(); i++) {
            vector<int> tmp = countLetters(B[i]);
            for(int j = 0; j < tmp.size(); j++) {
                bMax[j] = max(bMax[j], tmp[j]);
            }
        }
        
        vector<string> res;
        for(int i = 0; i < A.size(); i++) {
            vector<int> tmp = countLetters(A[i]);
            bool isRes = true;
            for(int j = 0; j < tmp.size(); j++) {
                if(tmp[j] < bMax[j]) {
                    isRes = false;
                    break;
                }
            }
            if(isRes) {
                res.push_back(A[i]);
            }
        }
        
        return res;
    }
    
    vector<int> countLetters(string aWord) {
        vector<int> cnt(26, 0);
        for(int i = 0; i < aWord.size(); i++) {
            cnt[aWord[i] - 'a']++;
        }
        return cnt;
    }
};