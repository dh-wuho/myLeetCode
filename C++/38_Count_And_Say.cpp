class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for(int i = 0; i < n - 1; i++) {
            string curr = "";
            int cnt = 1;
            for(int j = 0; j < res.size(); j += cnt) {
                cnt = 1;
                while(res[j] == res[j + cnt]) {
                    cnt++;
                }
                curr.push_back('0' + cnt);
                curr.push_back(res[j]); 
            }
            res = curr;
        }
        
        return res;
    }
};