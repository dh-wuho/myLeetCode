/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */



class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty()) {
            return {};
        }
        sort(intervals.begin(), intervals.end(), cmp());
        vector<Interval> res = {intervals[0]};
        int maxCon = 0;
        int currCon = 1;
        for(int i = 1; i < intervals.size(); i++) {
            if(res.back().end < intervals[i].start) {
                res.push_back(intervals[i]);
            }
            else {
                res.back().end = max(intervals[i].end, res.back().end);
            }
        }
        
        return res;
    }
    struct cmp {
        bool operator()(Interval& a, Interval& b) {
            return a.start < b.start;
        }
    };
};