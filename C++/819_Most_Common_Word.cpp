class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> dic(banned.begin(), banned.end());
        int maxTimes = -1;
        unordered_map<string, int> tMap;
        string res;
        
        for(int i = 0; i < paragraph.size(); i++) {
            paragraph[i] = isalpha(paragraph[i]) ? tolower(paragraph[i]) : ' ';    
        }
        
        stringstream ss(paragraph);
        string curr;
        while(ss >> curr) {
            if(dic.find(curr) == dic.end()) {
                tMap[curr]++;
                if(tMap[curr] > maxTimes) {
                    maxTimes = tMap[curr];
                    res = curr;
                }
            }
        }
        
        return res;
    }
};