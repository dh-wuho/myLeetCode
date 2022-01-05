class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> myStk;
        int res = 0;
        for(int i = 0; i < ops.size(); i++) {         
            switch(ops[i][0]) {
                case '+': {
                    int second = myStk.top();
                    myStk.pop();
                    int first = myStk.top();
                    myStk.push(second);
                    myStk.push(first + second);
                    res += myStk.top();
                    break;
                }
                case 'D': {
                    myStk.push(myStk.top() * 2);
                    res += myStk.top();
                    break;
                }
                case 'C': {
                    res -= myStk.top();
                    myStk.pop();
                    break;
                }
                default: {
                    myStk.push(stoi(ops[i]));
                    res += myStk.top();
                }
            }
        }
        
        return res;
    }
};