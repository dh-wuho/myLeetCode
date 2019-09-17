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
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> table;
        for(int i = 0; i < intervals.size(); i++) {
            table[intervals[i].start]++;
            table[intervals[i].end]--;
        }
        
        int currM = 0;
        int minM = 0;
        
        for(auto it : table) {
            currM += it.second;
            minM = max(currM, minM);
        }
        
        return minM;
    }
};



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
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp());
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < intervals.size(); i++) {
            if(!pq.empty() && pq.top() <= intervals[i].start) {
                pq.pop();
            }
            pq.push(intervals[i].end);
        }
        
        return pq.size();
    }
    struct cmp {
        bool operator()(Interval& a, Interval& b) {
            return a.start < b.start;
        }  
    };
};