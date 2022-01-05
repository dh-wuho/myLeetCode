class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<int> prev(3, 0);
        vector<int> curr(3, 0);
        
        for(int i = 0; i < costs.size(); i++) {
            curr[0] = costs[i][0] + min(prev[1], prev[2]);
            curr[1] = costs[i][1] + min(prev[0], prev[2]);
            curr[2] = costs[i][2] + min(prev[0], prev[1]);
            prev[0] = curr[0];
            prev[1] = curr[1];
            prev[2] = curr[2];
        }
        
        return min(min(curr[0], curr[1]), curr[2]);
    }
};