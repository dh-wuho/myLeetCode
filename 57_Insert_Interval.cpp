class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        if(n == 0) {
            res.push_back(newInterval);
            return res;
        }
        int curr = 0;
        while(curr < n && newInterval[0] > intervals[curr][1]) {
            res.push_back(intervals[curr]);
            curr++;
        }
        
        while(curr < n && newInterval[1] >= intervals[curr][0]) {
            newInterval[0] = min(newInterval[0], intervals[curr][0]);
            newInterval[1] = max(newInterval[1], intervals[curr][1]);
            curr++;
        }
        
        res.push_back(newInterval);
        while(curr < n) {
            res.push_back(intervals[curr]);
            curr++;
        }
        
        return res;
    }
};