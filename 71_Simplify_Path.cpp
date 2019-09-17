class Solution {
public:
    string simplifyPath(string path) {
        string res = "";
        
        for(int i = 0; i < path.size(); i++) {
            while(path[i] == '/' && i < path.size()) {
                i++;
            }
            if(i == path.size()) {
                break;
            }
            int start = i;
            while(path[i] != '/' && i < path.size()) {
                i++;
            }
            int end = i;
            string curr = path.substr(start, end -  start);
            if(curr == "..") {
                if(!res.empty()) {
                    res = res.substr(0, res.find_last_of('/'));
                }
            }
            else if(curr != ".") {
                res += '/' + curr;
            }
        }
        
        if(res.empty()) {
            res = "/";
        }
        
        return res;
    }
};


class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string oneString;
        string res;
        
        while(getline(ss, oneString, '/')) {
            if(oneString == "" || oneString ==".") {
                continue;
            }
            if(oneString == "..") {
                if(!res.empty()) {
                    res = res.substr(0, res.find_last_of('/'));
                }    
            }
            else {
                res += '/' + oneString;
            }
        }
        
        if(res.empty()) {
            res = "/";
        }
        
        return res;
    }
};