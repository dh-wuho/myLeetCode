class MovingAverage {
public:
    queue<int> q;
    int sum;
    int windowSize;
        
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        windowSize = size;
        sum = 0;
    }
    
    double next(int val) {
        if(q.size() == windowSize) {
            int popped = q.front();
            q.pop();
            q.push(val);
            sum -= popped;
            sum += val;
        }
        else {
            q.push(val);
            sum += val;
            return (double)sum / q.size();
        }
        return (double)sum / windowSize;
    }
};