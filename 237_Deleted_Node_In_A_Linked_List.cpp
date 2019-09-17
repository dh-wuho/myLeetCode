/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // ListNode* next = node->next;
        // auto is faster than specific type (here is ListNode), I don't know why now.
        auto next = node->next;
        *node = *node->next;
        delete next;
    }
};