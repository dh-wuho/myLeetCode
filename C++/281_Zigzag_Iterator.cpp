class ZigzagIterator {
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
    
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(!v1.empty()) {
            q.push(make_pair(v1.begin(), v1.end()));
        }
        if(!v2.empty()) {
            q.push(make_pair(v2.begin(), v2.end()));
        }
    }

    int next() {
        vector<int>::iterator head = q.front().first;
        vector<int>::iterator tail = q.front().second;
        q.pop();
        if(head + 1 != tail) {
            q.push(make_pair(head + 1, tail));
        }
        return *head;
    }

    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */