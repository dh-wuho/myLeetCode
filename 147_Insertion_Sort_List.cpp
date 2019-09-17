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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL) {
            return head;
        }
        
        ListNode* dummy = new ListNode(INT_MIN);
        ListNode* prev = dummy;
        ListNode* curr = head;
        ListNode* next = NULL;
        
        while(curr != NULL) {
            next = curr->next;
            
            while(prev->next != NULL && prev->next->val < curr->val) {
                prev = prev->next;
            }
            
            curr->next = prev->next;
            prev->next = curr;
            prev = dummy;
            curr = next;
        }
        
        return dummy->next;
    }
};