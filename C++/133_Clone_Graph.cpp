/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) {
            return node;
        }
        unordered_map<Node*, Node*> table;
        return dfs(node, table);
    }
    
    Node* dfs(Node* node, unordered_map<Node*, Node*>& table) {
        if(table.find(node) != table.end()) {
            return table[node];
        }
        Node* newNode = new Node(node->val);
        table[node] = newNode;
        for(Node* neighbor : node->neighbors) {
            newNode->neighbors.push_back(dfs(neighbor, table));    
        }
        return newNode;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) {
            return node;
        }
        unordered_map<Node*, Node*> table;
        queue<Node*> q;
        q.push(node);
        
        Node* newNode = new Node(node->val);
        table[node] = newNode;
        
        while(!q.empty()) {
            Node* oldNode = q.front();
            q.pop();
            for(Node* neighbor: oldNode->neighbors) {
                if(table.find(neighbor) == table.end()) {
                    table[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                table[oldNode]->neighbors.push_back(table[neighbor]);
            }
        }
        
        
        return newNode;
    }
};