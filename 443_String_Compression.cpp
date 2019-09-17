class Solution {
public:
    int compress(vector<char>& chars) {
        int start = 0;
        int compPos = 0;
        for(int curr = 0; curr < chars.size(); curr++) {
            if(curr + 1 == chars.size() || chars[curr] != chars[curr + 1]) {
                chars[compPos++] = chars[curr];
                if(start < curr) {
                    for(char c:to_string(curr - start + 1)) {
                        chars[compPos++] = c;
                    }
                }
                start = curr + 1;
            }
        }
        return compPos;
    }
};