class HitCounter {
public:
    vector<int> times;
    vector<int> hits;
    /** Initialize your data structure here. */
    HitCounter() {
        times.resize(300, 0);
        hits.resize(300, 0);
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int index = timestamp % 300;
        if(times[index] == timestamp) {
            hits[index]++;
        }
        else {
            hits[index] = 1;
            times[index] = timestamp;
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int res = 0;
        for(int i = 0; i < 300; i++) {
            if(timestamp - times[i] < 300) {
                res += hits[i];
            }
        }
        return res;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */