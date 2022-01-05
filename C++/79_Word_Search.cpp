class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int length = word.size();
        int h = board.size();
        if(h == 0) {
            return false;
        }
        int w = board[0].size();
        vector<vector<bool> > visited(h, vector<bool>(w, false));
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(dfs(board, word, visited, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int x, int y, int index) {
        if(index == word.size()) {
            return true;
        }
        
        if(x < 0 || x + 1> board.size() || y < 0 || y + 1 > board[0].size() || visited[x][y] || word[index] != board[x][y]) {
            return false;
        }
        
        visited[x][y] = true;
        bool res = dfs(board, word, visited, x, y - 1, index + 1) ||
                   dfs(board, word, visited, x, y + 1, index + 1) ||
                   dfs(board, word, visited, x - 1, y, index + 1) ||
                   dfs(board, word, visited, x + 1, y, index + 1);
        visited[x][y] = false;
        return res;
    }
};