/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) {
            return NULL;
        }
        
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                Node* tmp = q.front();
                q.pop();
                if(i < size - 1) {
                    tmp->next = q.front();    
                }
                if(tmp->left) {
                    q.push(tmp->left);
                }
                if(tmp->right) {
                    q.push(tmp->right);
                }
            }
        }
        
        return root;
    }
};


class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) {
            return NULL;
        }
        
        Node* tmp = root->next;
        while(tmp) {
            if(tmp->left) {
                tmp = tmp->left;
                break;
            }
            if(tmp->right) {
                tmp = tmp->right;
                break;
            }
            tmp = tmp->next;
        }
        
        if(root->left) {
            root->left->next = root->right ? root->right : tmp;
        }
        if(root->right) {
            root->right->next = tmp;
        }
                
        connect(root->right);
        connect(root->left);
        return root;
    }
};