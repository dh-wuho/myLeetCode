/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) {
            return NULL;
        }
        
        Node* oldNext = head;
        
        while(oldNext) {
            Node* tmp = oldNext->next;
            oldNext->next = new Node(oldNext->val, NULL, NULL);
            oldNext->next->next = tmp;
            oldNext = oldNext->next->next;
        }
        
        oldNext = head;
        while(oldNext) {
            if(oldNext->random) {
                oldNext->next->random = oldNext->random->next;   
            }
            oldNext = oldNext->next->next;
        }
        
        oldNext = head;
        Node* newHead = head->next;
        while(oldNext) {
            Node* tmp = oldNext->next;
            oldNext->next = tmp->next;
            if(oldNext->next) {
                tmp->next = oldNext->next->next;
            }
            oldNext = oldNext->next;
        }
        
        return newHead;
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    unordered_map<Node*, Node*> myMap;
    Node* copyRandomList(Node* head) {
        return helper(head);
    }
    
    Node* helper(Node* node) {
        if(node == NULL) {
            return NULL;
        }
        if(myMap.find(node) != myMap.end()) {
            return myMap[node];
        }
        
        Node* newNode = new Node(node->val, NULL, NULL);
        myMap[node] = newNode;
        newNode->next = helper(node->next);
        newNode->random = helper(node->random);
        
        return newNode;
    }
    
};