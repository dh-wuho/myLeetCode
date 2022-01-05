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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* small = new ListNode(-1);
        ListNode* big = new ListNode(-1);
        ListNode* s  = small;
        ListNode* b = big;
        
        while(head) {
            if(head->val < x) {
                small->next = head;
                small = small->next;
            }
            else {
                big->next = head;
                big = big->next;
            }
            head = head->next;
        }
        
        small->next = b->next;
        big->next = NULL;
        
        return s->next;
    }
};