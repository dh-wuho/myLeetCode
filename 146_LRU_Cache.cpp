class LRUCache {
public:
    int cap;
    list<pair<int, int> > cache;
    unordered_map<int, list<pair<int, int> >::iterator> aMap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        unordered_map<int, list<pair<int, int> >::iterator>:: iterator it = aMap.find(key);
        if(it == aMap.end()) {
            return -1;
        }
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        unordered_map<int, list<pair<int, int> >::iterator>:: iterator it = aMap.find(key);
        if(it != aMap.end()) {
            cache.erase(it->second);
        }
        cache.push_front(make_pair(key, value));
        aMap[key] = cache.begin();
        if(aMap.size() > cap) {
            int k = cache.back().first;
            aMap.erase(k);
            cache.pop_back();
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */