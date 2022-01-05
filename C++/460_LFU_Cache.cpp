class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if(freq.find(key) == freq.end()) {
            return -1;
        }

        freqLists[freq[key].second].erase(keyToNode[key]);
        freq[key].second++;
        freqLists[freq[key].second].push_back(key);
        keyToNode[key] = prev(freqLists[freq[key].second].end());
        
        if(freqLists[minFreq].size() == 0) {
            minFreq++;
        }
        return freq[key].first;
    }
    
    void put(int key, int value) {
        if(cap == 0) {
            return;
        }
        if(get(key) != -1) {
            freq[key].first = value;
            return;
        }
        
        if(freq.size() == cap) {
            int k = freqLists[minFreq].front();
            freq.erase(k);
            keyToNode.erase(k);
            freqLists[minFreq].pop_front();
        }
        
        freq[key] = make_pair(value, 1);
        freqLists[1].push_back(key);
        // anthoer method here:
        // keyToNode[key] = --freqLists[1].end();
        keyToNode[key] = prev(freqLists[1].end());
        minFreq = 1;
    }
    
private:
    int cap, minFreq;
    // key to node in freqList
    unordered_map<int, list<int>::iterator> keyToNode;
    // freq to freqList, key is saved in list
    unordered_map<int, list<int>> freqLists;
    // key to <value, freq>
    unordered_map<int, pair<int, int>> freq; 
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */