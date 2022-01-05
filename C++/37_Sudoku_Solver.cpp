class Solution {
public:   
    void solveSudoku(vector<vector<char>>& board) {
        dfsToFill(board, 0, 0);
    }
    
    bool dfsToFill(vector<vector<char> >& board, int r, int c) {
        if(c == 9) {
            return true;
        }
        int nr = (r + 1) % 9;
        int nc = (nr == 0) ? (c + 1) : c;
        
        if(board[r][c] != '.') {
            return dfsToFill(board, nr, nc); 
        }
        
        int b = 3 * (r / 3) + c / 3;
        for(int i = 1; i < 10; i++) {
            board[r][c] = '0' + i;
            if(isValid(board, r, c)) {
                if(dfsToFill(board, nr, nc)) {
                    return true;
                }
            }
            board[r][c] = '.';
        }
        
        return false;
    }
    
    bool isValid(vector<vector<char> >& board, int r, int c) {
        for(int i = 0; i < 9; i++) {
            if(i != c && board[r][i] == board[r][c]) {
                return false;
            }
            if(i != r && board[i][c] == board[r][c]) {
                return false;
            }
        }
        for(int i = r / 3 * 3; i < r / 3 * 3 + 3; i++) {
            for(int j = c / 3 * 3; j < c / 3 * 3 + 3; j++) {
                if(i != r && j != c && board[r][c] == board[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};