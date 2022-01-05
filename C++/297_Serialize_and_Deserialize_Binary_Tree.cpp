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
        ostringstream os;
        s_dfs(root, os);
        
        return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        
        return d_dfs(is);
    }
    
    // pre-order
    void s_dfs(TreeNode* root, ostringstream& os) {
        if(root == NULL) {
            os << "# ";
        }
        else {
            os << root->val << " ";
            s_dfs(root->left, os);
            s_dfs(root->right, os);
        }
    }
    
    TreeNode* d_dfs(istringstream& is) {
        string val;
        is >> val;
        if(val == "#") {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(stoi(val));
        root->left = d_dfs(is);
        root->right = d_dfs(is);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));