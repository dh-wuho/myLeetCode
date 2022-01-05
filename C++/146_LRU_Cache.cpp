class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) {
            return -1;
        }
        cache.splice(cache.begin(), cache, m[key]);
        return m[key]->second;
    }
    
    void put(int key, int value) {
        unordered_map<int, list<pair<int, int>>::iterator>::iterator it;
        it = m.find(key);
        if(it != m.end()) {
            cache.erase(it->second);
        }
        cache.push_front(make_pair(key, value));
        m[key] = cache.begin();
        if(m.size() > cap) {
            m.erase(cache.back().first);
            cache.pop_back();
        }
    }
    
private:
    int cap;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */