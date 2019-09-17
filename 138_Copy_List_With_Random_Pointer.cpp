/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> myMap;
        RandomListNode* old_next = head;
        RandomListNode* new_dummy = new RandomListNode(0);
        RandomListNode* new_next = new_dummy;
        while(old_next) {
            RandomListNode* tmp = new RandomListNode(old_next->label);
            myMap.emplace(old_next, tmp);
            new_next->next = tmp;
            old_next = old_next->next;
            new_next = new_next->next;
        }
        
        old_next = head;
        new_next = new_dummy->next;
        while(old_next) {
            new_next->random = myMap[old_next->random];
            new_next = new_next->next;
            old_next = old_next->next;
        }
        
        return new_dummy->next;
    }
};


/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *oldNext = head;
        RandomListNode *newHead, *newNext;
        
        if(head == NULL) {
            return NULL;
        }
        
        while(oldNext) {
            newNext = new RandomListNode(oldNext->label);
            newNext->next = oldNext->next;
            oldNext->next = newNext;
            oldNext = oldNext->next->next;
        }
        
        oldNext = head;
        while(oldNext) {
            if(oldNext->random) {
                oldNext->next->random = oldNext->random->next;
            }
            oldNext = oldNext->next->next;
        }
        
        newHead = head->next;
        oldNext = head;
        while(oldNext) {
            newNext = oldNext->next;
            oldNext->next = newNext->next;
            if(newNext->next) {
                newNext->next = newNext->next->next;
            }
            oldNext = oldNext->next;
        }
        
        return newHead;
    }
};