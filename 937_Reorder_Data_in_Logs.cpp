bool myCmp(string a, string b) {
    int i = a.find(' ');
    int j = b.find(' ');
    
    if(!isdigit(a[i + 1]) && !isdigit(b[j + 1])) {
        if(a.substr(i + 1) == b.substr(j + 1)) {
            return a.substr(0, i + 1) < b.substr(0, j + 1);
        }
        else {
            return a.substr(i + 1) < b.substr(j + 1);
        }
    }
    else if(!isdigit(a[i + 1])) {
        return true;
    }
    
    return false;
}

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), myCmp);
        return logs;
    }
};