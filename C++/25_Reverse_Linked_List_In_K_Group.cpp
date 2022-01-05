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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        int num = 0;
        while(curr) {
            num++;
            curr = curr->next;
        }
        curr = head;
        while(num >= k) {
            for(int i = 0; i < k - 1; i++) {
                ListNode* next = curr->next;
                if(next == NULL) {
                    break;
                }
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
            }
            prev = curr;
            curr = curr->next;
            num -= k;
        }
        
        return dummy->next;
    }
};