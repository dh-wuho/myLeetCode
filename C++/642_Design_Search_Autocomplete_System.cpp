class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for(int i = 0; i < sentences.size(); i++) {
            dict[sentences[i]] = times[i];
        }
        inStr.clear();
    }
    
    vector<string> input(char c) {
        if(c == '#') {
            dict[inStr]++;
            inStr.clear();
            return {};
        }
        
        inStr.push_back(c);
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
        for(auto it : dict) {
            // this doesn't work because truncate string costs too much time
            // if(inStr.size() <= it.first.size() && inStr == it.first.substr(0, inStr.size())) {
            //     pq.push(it);
            //     if(pq.size() > 3) {
            //         pq.pop();
            //     }
            // }
            bool match = true;
            for(int i = 0; i < inStr.size(); i++) {
                if(inStr[i] != it.first[i]) {
                    match = false;
                    break;
                }
            }
            if(match) {
                pq.push(it);
                if(pq.size() > 3) {
                    pq.pop();
                }
            }
        }
        
        int size = pq.size();
        vector<string> res(size);
        for(int i = size - 1; i > -1; i--) {
            res[i] = pq.top().first;
            pq.pop();
        }
        
        return res;
    }
    
private:
    unordered_map<string, int> dict;
    string inStr;
    
    struct cmp {
        bool operator()(pair<string, int>& a, pair<string, int>& b) {
            return (a.second > b.second) || (a.second == b.second && a.first < b.first); 
        }  
    };
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */



class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new trieNode();
        for(int i = 0; i < sentences.size(); i++) {
            insertToTrie(sentences[i], times[i]);
        }
        currNode = root;
        currStr = "";
    }
    
    vector<string> input(char c) {
        if(c == '#') {
            insertToTrie(currStr, 1);
            currStr.clear();
            currNode = root;
            return {};
        }
        
        currStr.push_back(c);
        if(currNode && currNode->children[c] != NULL) {
            currNode = currNode->children[c];
        }
        else {
            currNode = NULL;
            return {};
        }
        
        dfs(currNode);
        
        vector<string> res(pq.size());
        
        for(int i = pq.size() - 1; i > -1; i--) {
            res[i] = pq.top().first;
            pq.pop();
        }
        
        return res;
    }
    
private:
    struct trieNode {
        unordered_map<char,trieNode*> children;
        string str;
        int times;
        trieNode(): str(""), times(0) {}
    };
    
    struct cmp {
        bool operator()(pair<string, int>& a, pair<string, int>& b) {
            return (a.second > b.second) || (a.second == b.second && a.first < b.first);
        } 
    };
    
    trieNode* root;
    trieNode* currNode;
    string currStr;
    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
        
    void insertToTrie(string s, int times) {
        trieNode* curr = root;
        for(char c : s) {
            if(curr->children[c] == NULL) {
                curr->children[c] = new trieNode();
            }
            curr = curr->children[c];
        }
        curr->str = s;
        curr->times += times;
    }
    
    void dfs(trieNode* currNode) {
        if(!currNode->str.empty()) {
            pq.push(make_pair(currNode->str, currNode->times));
            if(pq.size() > 3) {
                pq.pop();
            }
        }

        for(auto it : currNode->children) {
            dfs(it.second);
        }
    }    
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */