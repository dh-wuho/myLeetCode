class RandomizedSet {
public:
    
    vector<int> storage;
    unordered_map<int, int> table;
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(table.count(val) == 1) {
            return false;
        }
        table[val] = storage.size();
        storage.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(table.count(val) == 0) {
            return false;
        }
        int tmp = storage.back();
        storage[table[val]] = tmp;
        table[tmp] = table[val];
        storage.pop_back();
        table.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return storage[rand() % storage.size()];
    }
};