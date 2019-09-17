/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {   
        if(root == NULL) {
            return root;
        }
        
        stack<Node*> nodeStk;
        Node* pre = NULL;
        Node* first = NULL;
        
        while(!nodeStk.empty() || root) {
            if(root) {
                nodeStk.emplace(root);
                root = root->left;
            }
            else {
                root = nodeStk.top();
                nodeStk.pop();
                if(first == NULL) {
                    first = root;
                }
                else {
                    pre->right = root;
                    root->left = pre;
                }
                pre = root;
                root = root->right;
            }
        }
        
        pre->right = first;
        first->left = pre;
        return first;
    }
};