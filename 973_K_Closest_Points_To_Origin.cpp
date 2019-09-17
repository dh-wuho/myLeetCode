class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int> >, cmp> maxHeap;
        for (int i = 0; i < points.size(); i++) {
            maxHeap.push(points[i]);
            if (maxHeap.size() > K) {
                maxHeap.pop();
            }
        }
        vector<vector<int> > res;
        while (!maxHeap.empty()) {
            res.push_back(maxHeap.top());
            maxHeap.pop();
        }
        return res;
    }
private:
    struct cmp {
        bool operator()(vector<int>& a, vector<int>& b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        }
    };
};