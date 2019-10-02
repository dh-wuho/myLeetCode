// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        char tmp[4] = {};
        int res = 0;
        int index = 0;
        while(n > 0) {
            res += min(read4(tmp), n);
            int minSize = (n, 4);
            for(int j = 0; j < minSize; j++) {
                buf[index++] = tmp[j];
            }
            n -= 4;
        }
        
        return res;
    }
};