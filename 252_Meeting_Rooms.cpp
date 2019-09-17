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
    int canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp());
        
        for(int i = 1; i < intervals.size(); i++) {
           if(intervals[i].start < intervals[i -1].end) {
               return false;
           }
        }
        
        return true;
    }
    
    struct cmp {
        bool operator()(Interval& a, Interval& b) {
            return a.start < b.start;
        }  
    };
};