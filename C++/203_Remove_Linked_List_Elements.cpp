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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        
        while(head) {
            if(head->val == val) {
                ListNode* tmp = head;
                pre->next = head->next;
                head = head->next;
                delete tmp;
            }
            else {
                head = head->next;
                pre = pre->next;
            }
        }
        
        return dummy->next;
    }
};