// O(n!)

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        // store existing queen pos
        vector<int> pos;
        vector<vector<string> > res;
        backTrack(n, 0, pos, res);
        return res;
    }
    
    void backTrack(int n, int row, vector<int> pos, vector<vector<string> >& res) {
        if(n == pos.size()) {
            vector<string> oneRes(n, string(n, '.'));
            for(int i = 0; i < n; i++) {
                oneRes[i][pos[i]] = 'Q';
            }
            res.push_back(oneRes);
            return;
        }
        
        for(int i = 0; i < n; i++) {
            if(isValid(pos, row, i)) {
                pos.push_back(i);
                backTrack(n, row + 1, pos, res);
                pos.pop_back();
            }
        }
    }
    
    bool isValid(vector<int> pos, int row, int col) {
        for(int i = 0; i < pos.size(); i++) {
            if(col == pos[i] || abs(row - i) == abs(col - pos[i])) {
                return false;
            }
        }
        return true;
    }
    
};