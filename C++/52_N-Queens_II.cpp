class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<int> qPos;
        queenDFS(n, 0, qPos, res);
        return res;
    }
    
    void queenDFS(int n, int x, vector<int>& pos, int& res) {
        if(pos.size() == n) {
            res++;
            return;
        }
        
        for(int i = 0; i < n; i++) {
            if(isValid(pos, x, i)) {
                pos.push_back(i);
                queenDFS(n, x + 1, pos, res);
                pos.pop_back();
            }
        }
    }
    
    bool isValid(vector<int> pos, int x, int y) {
        for(int i = 0; i < pos.size(); i++) {
            if(y == pos[i] || abs(x - i) == abs(y - pos[i])) {
                return false;
            }
        }
        return true;
    }
};