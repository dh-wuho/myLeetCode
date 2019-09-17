class Solution {
public:
    string minWindow(string s, string t) {
         unordered_map<char, int> table;
        for(char c : t) {
            table[c]++;
        }
        
        int left = 0;
        int cnt = 0;
        int minLength = s.size() + 1;
        string res;
        
        for(int right = 0; right < s.size(); right++) {
            table[s[right]]--;
            if(table[s[right]] >= 0) {
                cnt++;
            }
            while(cnt == t.size()) {
                if(right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    res = s.substr(left, minLength);
                }
                table[s[left]]++;
                if(table[s[left]] > 0) {
                    cnt--;
                }
                left++;
            }
        }
        
        return res;
    }
};