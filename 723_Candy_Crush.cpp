class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int height = board.size();
        int width = board[0].size();
        bool isStable = false;
        
        while(!isStable) {
            isStable = true;
            for(int i = 0; i < height; i++) {
                for(int j = 0; j < width; j++) {
                    if(board[i][j] == 0) {
                        continue;
                    }
                    int val = abs(board[i][j]);
                    // vertically
                    if(i + 2 < height && abs(board[i + 1][j]) == val 
                       && abs(board[i + 2][j]) == val) {
                        isStable = false;
                        board[i][j] = -val;
                        board[i + 1][j] = -val;
                        board[i + 2][j] = -val;
                    }
                    // horizontally
                    if(j + 2 < width && abs(board[i][j + 1]) == val 
                       && abs(board[i][j + 2]) == val) {
                        isStable = false;
                        board[i][j] = -val;
                        board[i][j + 1] = -val;
                        board[i][j + 2] = -val;
                    }
                }
            }
            
            
            
            for(int i = 0; i < height; i++) {
                for(int j = 0; j < width; j++) {
                    if(board[i][j] < 0) {
                        board[i][j] = 0;
                    }
                }
            }
            
            for(int j = 0; j < width; j++) {
                int bot = height - 1;
                for(int i = height - 1; i > -1; i--) {
                    if(board[i][j] != 0) {
                        swap(board[i][j], board[bot][j]);
                        bot--;
                    }
                }
            }
        }
        
        return board;
    }
};