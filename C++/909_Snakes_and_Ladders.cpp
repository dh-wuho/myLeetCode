class Solution {
public:
    vector<int> getIndices(int val, int n) {
        int i = (val - 1) / n;
        int j = (val - 1) % n;
        if(i % 2 == 1) {
            j = n - j - 1;
        }
        i = n - i - 1;
        
        return {i, j};
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int steps = 0;
        int n = board.size();
        queue<int> q;
        q.push(1);
        
        while(!q.empty()) {
            int size = q.size();
            for(int  i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                
                if(curr == n * n) {
                    return steps;
                }

                for(int j = 0; j < 6; j++) {
                    int next = curr + j + 1;
                    if(next > n * n) {
                        break;
                    }

                    vector<int> indices = getIndices(next, n);
                    int ni = indices[0];
                    int nj = indices[1];
                    if(board[ni][nj] != -1) {
                        next = board[ni][nj];
                    }

                    if(board[ni][nj] != n * n + 1) {
                        q.push(next);
                        board[ni][nj] = n * n + 1;
                    }
                }   
            }
            steps++;
        }
        
        return -1;
    }
};