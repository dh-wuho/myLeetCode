class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int height = board.size();
        if(height == 0) {
            return;
        }
        int width = board[0].size();
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                if(i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                    if(board[i][j] == 'O') {
                        dfs(board, i, j);
                    }
                }   
            }
        }
        
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if(board[i][j] == '1') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int i, int j) {
        cout << i << " " << j << endl;
        board[i][j] = '1';
        if(i > 0 && board[i - 1][j] == 'O') {
            dfs(board, i - 1, j);
        }
        if(i + 1 < board.size() && board[i + 1][j] == 'O') {
            dfs(board, i + 1, j);
        }
        if(j > 0 && board[i][j - 1] == 'O') {
            dfs(board, i, j - 1);
        }
        if(j + 1 < board[0].size() && board[i][j + 1] == 'O') {
            dfs(board, i, j + 1);
        }
    }
};