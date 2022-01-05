class Solution {
public:
    string decodeString(string s) {
        stack<int> numStk;
        stack<string> strStk;
        string res = "";
        int cnt = 0;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                cnt = cnt * 10 + s[i] - '0';
            }
            else if(s[i] == '[') {
                // store the times of next string and last res
                numStk.push(cnt);
                strStk.push(res);
                cnt = 0;
                res.clear();
            }
            else if(s[i] == ']') {
                int times = numStk.top();
                numStk.pop();
                for(int j = 0; j < times; j++) {
                    strStk.top() += res;
                }
                res = strStk.top();
                strStk.pop();
            }
            else {
                res += s[i];
            }
        }
        
        return res;
    }
};