class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool> > row(9, vector<bool>(9, false));
        vector<vector<bool> > col(9, vector<bool>(9, false));
        vector<vector<bool> > box(9, vector<bool>(9, false));
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int curr = board[i][j] - '1';
                    // project box index to row; i / 3 = {0, 1, 2}, j / 3 = {0, 1, 2};
                    int k = 3 * (i / 3) + j / 3;
                    if(row[i][curr] || col[curr][j] || box[k][curr]) {
                        return false;
                    }
                    row[i][curr] = true;
                    col[curr][j] = true;
                    box[k][curr] = true;
                }
            }
        }
        
        return true;
    }
};