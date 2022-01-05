class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> m;
        
        m['6'] = '9';
        m['9'] = '6';
        m['0'] = '0';
        m['1'] = '1';
        m['8'] = '8';
        
        
        int left = 0;
        int right = num.size() - 1;
        while(left <= right) {
            if(m.count(num[left]) == 0 || m.count(num[right]) == 0) {
                return false;
            }
            if(m.count(num[left]) == 1 && m[num[left]] != num[right]) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};