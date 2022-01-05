class Solution {
public:
    void reverseWords(vector<char>& str) {
        reverse(str.begin(), str.end());
        int start = 0;
        int end = 0;
        int n = str.size();
        while(start < n && end < n) {
            while(end < n && str[end] != ' ') {
                end++;
            }
            reverse(str.begin() + start, str.begin() + end);
            end++;
            start = end;
        }
    }
};