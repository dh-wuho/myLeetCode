class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        /*
        state 0: dead to dead
        state 1: live to live
        state 2: live to dead
        state 3: dead to live
        */
        
        int h = board.size();
        int w = board[0].size();
        vector<int> di = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dj = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                int cnt = 0;
                for(int k = 0; k < 8; k++) {
                    int ci = i + di[k];
                    int cj = j + dj[k];
                    
                    if(ci >= 0 && ci < h && cj >=0 && cj < w && (board[ci][cj] == 1 || board[ci][cj] == 2)) {
                        cnt++;
                    }
                }
                
                if(board[i][j] && (cnt < 2 || cnt > 3)) {
                    board[i][j] = 2;
                }
                if(board[i][j] == 0 && cnt == 3) {
                    board[i][j] = 3;
                }
            }
        }
    
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                board[i][j] %= 2;
            }
        }
    
    }    
};