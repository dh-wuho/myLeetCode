class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<vector<string>> paths;
        vector<string> usedWords;
        int level = 1;
        int minLevel = INT_MAX;
        paths.push({beginWord});
        
        while(!paths.empty()) {
            vector<string> tmp = paths.front();
            paths.pop();
            if(tmp.size() > level) {
                for(string word : usedWords) {
                    dict.erase(word);
                }
                usedWords.clear();
                level = tmp.size();
                if(level > minLevel) {
                    break;
                }
            }
            
            string last = tmp.back();
            for(int i = 0; i < last.size(); i++) {
                string newLast = last;
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    newLast[i] = ch;
                    if(!dict.count(newLast)) {
                        continue;
                    }
                    usedWords.push_back(newLast);
                    vector<string> newPath = tmp;
                    newPath.push_back(newLast);
                    if(newLast == endWord) {
                        res.push_back(newPath);
                        minLevel = level;
                    }
                    else {
                        paths.push(newPath);
                    }
                }
            }
        }
        
        return res;
    }
};