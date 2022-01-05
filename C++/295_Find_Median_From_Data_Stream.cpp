class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int> > minHeap;
    priority_queue<int> maxHeap;
    
    void addNum(int num) {
        maxHeap.emplace(num);
        
        minHeap.emplace(maxHeap.top());
        maxHeap.pop();
        
        if(maxHeap.size() < minHeap.size()) {
            maxHeap.emplace(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()) {
            return ((double)maxHeap.top() + (double)minHeap.top()) / 2;
        }
        
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */