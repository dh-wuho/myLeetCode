class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int newDic[26];
        for(int i = 0; i < order.size(); i++) {
            newDic[order[i] - 'a'] = i;
        }
        
        for(int i = 0; i < words.size() - 1; i++) {
            if(!cmpTwoWords(words[i], words[i + 1], newDic)) {
                return false;
            }
        }
        return true;
    }
    
    bool cmpTwoWords(string prev, string next, int newDic[]) {
        int minLength = min(prev.size(), next.size());
        for(int i = 0 ; i < minLength; i++) {
            if(newDic[prev[i] - 'a'] < newDic[next[i] - 'a']) {
                return true;
            }
            if(newDic[prev[i] - 'a'] > newDic[next[i] - 'a']) {
                return false;
            }
        }
        return prev.size() < next.size() ? true : false;
    }
};