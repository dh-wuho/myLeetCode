class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> myStk;
        int res = 0;
        for(int i = 0; i < tokens.size(); i++) {
            int sLength = tokens[i].size();
            if(isdigit(tokens[i][sLength - 1])) {
                myStk.push(stoi(tokens[i]));
            }
            else {
                int second = myStk.top();
                myStk.pop();
                int first = myStk.top();
                myStk.pop();
                switch(tokens[i][0]) {
                    case '+': {
                        first += second;
                        break;
                    }
                    case '-': {
                        first -= second;
                        break;
                    }
                    case '*': {
                        first *= second;
                        break;
                    }
                    case '/': {
                        first /= second;
                        break;   
                    }
                }
                myStk.push(first);
            }
        }
        
        return myStk.top();
    }
};