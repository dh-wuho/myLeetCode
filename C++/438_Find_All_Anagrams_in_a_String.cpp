class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> m;
        for(char c : p) {
            m[c]++;
        }
        
        int cnt = p.size();
        int left = 0;
        int right = 0;
        vector<int> res;
        
        while(right < s.size()) {
            if(m[s[right]] > 0) {
                cnt--;
            }
            m[s[right]]--;
            if(cnt == 0) {
                res.push_back(left);
            }
            if(right - left + 1 == p.size()) {
                if(m[s[left]] > -1) {
                    cnt++;
                }
                m[s[left]]++;
                left++;
            }
            right++;
        }
        
        return res;
        
    }
};