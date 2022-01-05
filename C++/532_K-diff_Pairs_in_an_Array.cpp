class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) {
            return 0;
        }
        unordered_map<int, int> m;
        for(int n : nums) {
            m[n]++;
        }
        
        int res = 0;
        for(unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            if((k == 0 && it->second > 1) || (k != 0 && m.find(it->first + k) != m.end())) {
                res++;
            }
        }
        
        return res;
    }
};