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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* preM = dummy;
        for(int i = 1; i < m; i++) {
            preM = preM->next;
        }
        
        ListNode* curr = preM->next;
        for(int i = m; i < n; i++) {
            ListNode* next = curr->next;
            curr->next = next->next;
            next->next = preM->next;
            preM->next = next;   
        }
        
        return dummy->next;
    }
};