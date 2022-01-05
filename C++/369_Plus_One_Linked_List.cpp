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
    ListNode* plusOne(ListNode* head) {
        ListNode* right = NULL;
        ListNode* curr = head;
        while(curr) {
            if(curr->val != 9) {
                right = curr;
            }
            curr = curr->next;
        }
        
        if(right == NULL) {
            right = new ListNode(0);
            right->next = head;
            head = right;    
        }
        right->val++;
        curr = right->next;        
        
        while(curr) {
            curr->val = 0;
            curr = curr->next;
        }
        
        return head;
    }
};