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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* first = head;
        ListNode* second = slow->next;
        slow->next = NULL;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        
        while(second) {
            next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }
        second = prev;
        
        while(first && second) {
            next = second->next;
            second->next = first->next;
            first->next = second;
            first = second->next;
            second = next;
        }
    }
};