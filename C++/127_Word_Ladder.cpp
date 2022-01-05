class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(dict.count(endWord) == 0) {
            return 0;
        }
        
        int res = 1;
        int wLength = beginWord.size();
        queue<string> q;
        q.push(beginWord);
        
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();
                for(int j = 0; j < wLength; j++) {
                    string newWord = word;
                    for(char c = 'a'; c <= 'z'; c++) {
                        newWord[j] = c;
                        if(dict.count(newWord) != 0 && newWord != word) {
                            if(newWord == endWord) {
                                return res + 1;
                            }
                            q.push(newWord);
                            // 防止重复访问
                            dict.erase(newWord);
                        }
                    }
                }
            }
            res++;
        }
        
        return 0;
    }
};