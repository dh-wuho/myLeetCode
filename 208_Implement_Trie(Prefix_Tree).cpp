class Trie {
public:
    /** Initialize your data structure here. */
    struct node {
        node* subNodes[26];
        bool isWord;
        node(): isWord(false) {
            for(int i = 0; i < 26; i++) {
                subNodes[i] = NULL;
            }
        }
    };
    
    node* root;
    
    Trie() {
        root = new node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        node* curr = root;
        for(int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if(curr->subNodes[index] == NULL) {
                curr->subNodes[index] = new node();
            }
            curr = curr->subNodes[index];
        }
        curr->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node* curr = root;
        for(int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if(curr->subNodes[index] == NULL) {
                return false;
            }
            curr = curr->subNodes[index];
        }
        if(curr->isWord) {
            return true;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node* curr = root;
        for(int i = 0; i < prefix.size(); i++) {
            int index = prefix[i] - 'a';
            if(curr->subNodes[index] == NULL) {
                return false;
            }
            curr = curr->subNodes[index];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */