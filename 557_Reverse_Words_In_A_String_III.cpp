class Solution {
public:
    string reverseWords(string s) {
        int front = 0;
        int length = s.size();
        for(int i = 0; i < length + 1; i++) {
            if(s[i] == ' ' || i == length) {
                reverse(&s[front], &s[i]);
                front = i + 1;
            }
        }
        
        return s;
    }
}; 


class Solution {
public:
    string reverseWords(string s) {
        int start = 0, end = 0, n = s.size();
        while (start < n && end < n) {
            while (end < n && s[end] != ' ') ++end;
            for (int i = start, j = end - 1; i < j; ++i, --j) {
                swap(s[i], s[j]);
            }
            end++;
            start = end;
        }
        return s;
    }
};
