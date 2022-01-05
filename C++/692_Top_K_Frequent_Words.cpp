// O(nlgk)

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> table;
        for(string s : words) {
            table[s]++;
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string> >, cmp> myq;
        
        for(auto it : table) {
            myq.push(make_pair(it.second, it.first));
            if(myq.size() > k) {
                myq.pop();
            }
        }
        
        vector<string> res;
        while(!myq.empty()) {
            res.push_back(myq.top().second);
            myq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    struct cmp {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            return (a.first > b.first) || ((a.first == b.first) && (a.second < b.second));
        }
    };
};