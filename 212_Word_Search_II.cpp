class Trie {
public:
    /** Initialize your data structure here. */
    vector<Trie*> subNodes;
    bool isWord;
    
    Trie(): isWord(false) {
        subNodes = vector<Trie*>(26, NULL);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* curr = this;
        for(int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if(curr->subNodes[index] == NULL) {
                curr->subNodes[index] = new Trie();
            }
            curr = curr->subNodes[index];
        }
        curr->isWord = true;
    }
};


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if(words.empty() || board.empty()) {
            return res;
        }
        Trie* myT = new Trie();
        for(int i = 0; i < words.size(); i++) {
            myT->insert(words[i]);
        }
        
        int height = board.size();
        int width = board[0].size();
        vector<vector<bool> > visited(height, vector<bool>(width, false));
        
        string curr = "";
        
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                backTrack(board, i, j, visited, myT, curr, res);
            }
        }
        
        return res;
    }
    
    void backTrack(vector<vector<char> >& board, int x, int y, vector<vector<bool>>& visited, Trie* myT, string& curr, vector<string>& res) {
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) {
            return;
        }
        
        int index = board[x][y] - 'a';

        if(myT->subNodes[index] == NULL || visited[x][y]) {
            return;
        }
        
        myT = myT->subNodes[index];
        visited[x][y] = true;
        curr.push_back(board[x][y]);
        if(myT->isWord) {
            myT->isWord = false;
            res.push_back(curr);
        }
        
        backTrack(board, x + 1, y, visited, myT, curr, res);
        backTrack(board, x - 1, y, visited, myT, curr, res);
        backTrack(board, x, y + 1, visited, myT, curr, res);
        backTrack(board, x, y - 1, visited, myT, curr, res);
        
        visited[x][y] = false;
        curr.pop_back();
    }
};