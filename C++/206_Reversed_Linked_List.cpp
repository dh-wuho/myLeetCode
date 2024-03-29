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
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL;
        while(head) {
            ListNode* next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        
        return newHead;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return newHead;
    }
};