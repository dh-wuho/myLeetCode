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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return true;
        }
        
        // find mid
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // reverse bear half
        ListNode* prev = slow;
        ListNode* curr = prev->next;
        while(curr && curr->next) {
            ListNode* next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        
        slow = slow->next;
        while(slow) {
            if(slow->val != head->val) {
                return false;
            }
            slow = slow->next;
            head = head->next;
        }
        
        return true;
    }
};