/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;
        while(curr) {
            if(curr->child) {
                Node* next = curr->next;
                Node* last = curr->child;
                while(last->next) {
                    last = last->next;
                }
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = NULL;
                last->next = next;
                if(next) {
                    next->prev = last;   
                }
            }
            curr = curr->next;
        }
        return head;
    }
};





/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;
        while(curr) {
            if(curr->child) {
                curr->child = flatten(curr->child);
                Node* next = curr->next;
                Node* last = curr->child;
                while(last->next) {
                    last = last->next;
                }
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = NULL;
                last->next = next;
                if(next) {
                    next->prev = last;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};