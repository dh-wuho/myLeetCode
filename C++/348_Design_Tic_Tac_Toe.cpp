class TicTacToe {
public:
    vector<int> rCount, cCount;
    int dCount, rdCount;
    int winner;
    int size;
    
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rCount.resize(n, 0);
        cCount.resize(n, 0);
        dCount = 0;
        rdCount = 0;
        winner = 0;
        size = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if(winner != 0) {
            return winner;
        }
        int add = (player == 1 ? 1 : -1);
        rCount[row] += add;
        cCount[col] += add;
        if(row == col) {
            dCount += add;
        }
        if(row + col == size - 1) {
            rdCount += add;
        }
        
        return (abs(rCount[row]) == size || abs(cCount[col]) == size
             || abs(dCount) == size || abs(rdCount) == size) ? player : 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */