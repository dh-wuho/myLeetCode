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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = head;
        ListNode* curr = head;
        for(int i = 0; i < n; i++) {
            curr = curr->next;
        }
        
        if(curr == NULL) {
            ListNode* res = head->next;
            delete head;
            return res;
        }
        
        while(curr->next) {
            curr = curr->next;
            prev = prev->next;
        }
        
        ListNode* tmp = prev->next;
        prev->next = prev->next->next;
        delete tmp;
        
        return head;
    }
}; 