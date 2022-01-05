/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        
        if(root == NULL) {
            return res;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            if(tmp == NULL) {
                res += "# ";
            }
            else {
                res += (to_string(tmp->val) + " ");
                q.push(tmp->left);
                q.push(tmp->right);
            }
        }
        
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) {
            return NULL;
        }  
        
        istringstream is(data);
        queue<TreeNode*> q;
        string val;
        
        is >> val;
        TreeNode* root = new TreeNode(stoi(val));
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            if(!(is >> val)) {
                break;
            }
            if(val != "#") {
                tmp->left = new TreeNode(stoi(val));
                q.push(tmp->left);
            }
            if(!(is >> val)) {
                break;
            }
            if(val != "#") {
                tmp->right = new TreeNode(stoi(val));
                q.push(tmp->right);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));    `