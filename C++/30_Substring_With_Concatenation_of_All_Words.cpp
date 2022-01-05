class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int sLength = s.size();
        int wLength = words.size();
        vector<int> res;
        if(sLength == 0 || wLength == 0) {
            return res;
        }

        int wordSize = words[0].size();
        unordered_map<string, int> origin;
        for(int i = 0; i < wLength; i++) {
            origin[words[i]]++;
        }
        
        // sliding window
        for(int i = 0; i < wordSize; i++) {
            unordered_map<string, int> temp = origin;
            int cnt = wLength;
            for(int j = i; j + wordSize < sLength + 1; j += wordSize) {
                string curr = s.substr(j, wordSize);
                if(temp[curr] > 0) {
                    cnt--;
                }
                temp[curr]--;
                
                // wordSize * wLength is the max window size.
                // this part is to refresh map temp for new substring
                if(j >= wordSize * wLength) {
                    string head = s.substr(j - wordSize * wLength, wordSize);
                    temp[head]++;
                    if(temp[head] > 0) {
                        cnt++;
                    }
                }
                
                if(cnt == 0) {
                    res.push_back(j - wordSize * (wLength - 1));
                }
            }
        }
        
        return res;
    }
};